# 🐚 Minishell

A lightweight Unix shell implementation built in C as part of the 42 Common core.

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Technical Details](#technical-details)
- [Memory Management](#memory-management)
- [Testing](#testing)
- [Project Structure](#project-structure)
- [Authors](#authors)

## 🎯 About

Minishell is a simple shell program that replicates basic functionality of bash. This project deepens understanding of processes, file descriptors, and Unix system calls while implementing a command-line interpreter from scratch.

**Grade:** ✅ Passing (All mandatory features implemented)

**Memory Leaks:** ✅ Zero leaks (Valgrind verified)

## ✨ Features

### Core Functionality
- ✅ Interactive command prompt with history navigation
- ✅ Command execution with PATH resolution
- ✅ Absolute and relative path execution
- ✅ Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)
- ✅ Exit status tracking (`$?`)

### Redirections
- ✅ Input redirection (`<`)
- ✅ Output redirection (`>`)
- ✅ Append mode (`>>`)
- ✅ Heredoc (`<<`)

### Pipes
- ✅ Single pipes (`cmd1 | cmd2`)
- ✅ Multiple pipes (`cmd1 | cmd2 | cmd3 | ...`)
- ✅ Pipes with redirections

### Quote Handling
- ✅ Single quotes (`'`) - no expansion
- ✅ Double quotes (`"`) - variable expansion enabled

### Variable Expansion
- ✅ Environment variables (`$VAR`, `$HOME`, `$USER`)
- ✅ Exit status (`$?`)
- ✅ Multiple variables in same string

### Built-in Commands
- `echo` with `-n` option
- `cd` with relative/absolute paths and `cd -`
- `pwd` (print working directory)
- `export` (set environment variables)
- `unset` (remove environment variables)
- `env` (display environment)
- `exit` with numeric exit codes

## 🔧 Installation

### Prerequisites
- GCC compiler
- GNU Make
- readline library

### Build
```bash
git clone //LINK DE CLONE
cd minishell
make
```

### Clean
```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Rebuild everything
```

## 🚀 Usage

### Run the shell
```bash
./minishell
```

### Example commands
```bash
minishell> echo "Hello, World!"
Hello, World!

minishell> ls -la | grep minishell | wc -l
5

minishell> export MY_VAR=42
minishell> echo "The answer is $MY_VAR"
The answer is 42

minishell> cat << EOF | grep hello
> hello world
> goodbye
> EOF
hello world

minishell> cd /tmp && pwd
/tmp

minishell> exit 0
exit
```

## 🛠️ Built-in Commands

| Command | Description | Examples |
|---------|-------------|----------|
| `echo` | Print arguments | `echo "text"`, `echo -n "no newline"` |
| `cd` | Change directory | `cd /path`, `cd ..`, `cd -` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variable | `export VAR=value`, `export` |
| `unset` | Remove environment variable | `unset VAR` |
| `env` | Display environment | `env` |
| `exit` | Exit the shell | `exit`, `exit 42` |

## 🔍 Technical Details

### Architecture

```
Input → Lexer/Tokenizer → Parser → Expander → Executor
```

1. **Lexer**: Splits input into tokens (words, operators, redirects)
2. **Parser**: Builds command structures with arguments and redirections
3. **Expander**: Resolves environment variables and quotes
4. **Executor**: Executes commands (builtins or external programs)

### Key Components

#### Tokenization
- Quote-aware string splitting
- Operator detection (`|`, `<`, `>`, `>>`, `<<`)
- Preserves quoted strings

#### Parsing
- Separates commands from redirections
- Handles heredoc delimiters
- Builds argument arrays

#### Execution
- Fork/exec for external commands
- Pipeline creation with pipes
- Builtin command handling
- Redirection setup before execution

### Data Structures

```c
// Token structure
typedef struct s_token {
	char            *value;
	char            *type;
	struct s_token  *next;
	struct s_token  *prev;
} t_token;

// Command structure
typedef struct s_cmd {
	char    **args;
	char    *infile;
	char    *outfile;
	int     append;
	int     heredoc_fd;
} t_cmd;

// Environment structure
typedef struct s_env {
	char            *name;
	char            *value;
	struct s_env    *next;
} t_env;

// Main structure
typedef struct s_mini {
	t_env   *env_list;
	t_token *token_list;
	t_cmd   *current_cmd;
	int     exit_status;
} t_mini;
```

## 💾 Memory Management

### Zero Memory Leaks
All dynamically allocated memory is properly freed:

- ✅ Command structures (`free_cmd`)
- ✅ Token lists (`free_token_list`)
- ✅ Environment variables (`free_env_list`)
- ✅ Argument arrays (`free_array`)
- ✅ Pipeline resources (`free_pipes`)
- ✅ Readline history (`rl_clear_history`)

### Cleanup Strategy
- Centralized `cleanup_all()` function
- Proper cleanup before all `exit()` calls
- Error handling with cleanup on failure paths

### Verification
```bash
make leaks  # Run with Valgrind
```

Expected output:
```
ERROR SUMMARY: 0 errors from 0 contexts
```

## 🧪 Testing

### Manual Testing
```bash
# Basic commands
echo test
pwd
ls -la

# Pipes
ls | grep mini | wc -l

# Redirections
echo "test" > file.txt
cat < file.txt
cat << EOF
hello
world
EOF

# Variables
export TEST=42
echo $TEST
echo "Value: $TEST"

# Quotes
echo 'No $expansion'
echo "With $expansion"

# Exit status
ls non_existent_file
echo $?

# Builtins
cd /tmp
pwd
cd -
unset TEST
env | grep TEST
exit 0
```

### Memory Leak Testing
```bash
# With Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./minishell

# Quick check with make
make leaks
```

### Edge Cases Tested
- Empty input
- Only whitespace
- Multiple consecutive pipes
- Redirections without commands
- Invalid commands
- Unclosed quotes (not handled - bash behavior)
- Large number of environment variables
- Long command lines

## 📁 Project Structure

```
minishell/
├── main.c                      # Entry point and main loop
├── clean.c                     # Memory cleanup functions
├── minishell.h                 # Header file
├── Makefile                    # Build configuration
├── README.md                   # Readme file
├── libft/                      # Custom C library
├── tokenize/
│   ├── tokenize.c             # Input tokenization
│   ├── token_utils.c          # Token manipulation
│   └── split_cmd.c            # Quote-aware splitting
├── parsing/
│   ├── parser.c               # Command parsing
│   ├── heredoc.c              # Heredoc handling
│   ├── expand.c               # Variable expansion
│   ├── expand_utils.c         # Expansion helpers
│   ├── process_quotes.c       # Quote processing
│   ├── build_args.c           # Argument array building
│   ├── build_args_utils.c     # Argument helpers
│   ├── extracting.c           # Token extraction
│   └── pipeline_parsing.c     # Pipeline parsing
├── path_cmds/
│   ├── exec.c                 # Command execution
│   ├── execute_simple_command.c
│   ├── execute_pipeline.c     # Pipeline execution
│   ├── execute_pipeline_utils.c
│   ├── get_path.c             # PATH resolution
│   └── redirects.c            # Redirection handling
├── builtin_cmds/
│   ├── builtins.c             # Builtin dispatcher
│   ├── execute_echo.c         # echo command
│   ├── execute_cd.c           # cd command
│   ├── execute_pwd.c          # pwd command
│   ├── execute_export.c       # export command
│   ├── export_utils.c         # export helpers
│   ├── execute_unset.c        # unset command
│   ├── execute_env.c          # env command
│   ├── execute_exit.c         # exit command
│   └── exit_utils.c           # exit helpers
├── env/
│   ├── env.c                  # Environment initialization
│   └── env_utils.c            # Environment utilities
└── signals/
	└── signals.c              # Signal handling
```

## 👥 Authors

**Development Team:**
- **malcosta** - Execution, parsing, pipes, redirects, variable expansion, quotes, signals
- **bfernan2** - Builtins (echo, cd, export, unset, env, exit, pwd)

## 📚 Resources

- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/)
- [Unix System Calls](https://man7.org/linux/man-pages/)
- [Process Control](https://www.gnu.org/software/libc/manual/html_node/Process-Control.html)
- [42 School Projects](https://github.com/42School)
