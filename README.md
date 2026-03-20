# 🐚 Minishell

*This project was created as part of the 42 curriculum by malcosta and bfernan2*

---

## 📖 Description

**Minishell** is a simplified Unix command interpreter developed in C as part of the 42 School curriculum. The project replicates basic functionalities of the **bash** shell, allowing users to execute commands, manage processes, handle redirections and pipes, and expand environment variables.

### Purpose

The main goal is to deepen understanding of:
- Unix processes and system calls (fork, exec, pipe, wait)
- File descriptors and I/O redirections
- Command parsing and tokenization
- Dynamic memory management
- Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)

### Overview

Minishell reads user commands, processes input with support for quotes and variable expansion, executes built-in and external commands, and manages pipelines and redirections — all with strict memory management (zero memory leaks verified with Valgrind).

**Status:** ✅ Passing (All mandatory features implemented)  
**Memory Leaks:** ✅ Zero leaks (Valgrind verified)

### Features

**Core Functionality:**
- ✅ Interactive command prompt with history navigation
- ✅ Command execution with PATH resolution
- ✅ Absolute and relative path execution
- ✅ Signal handling (Ctrl+C, Ctrl+D, Ctrl+\\)
- ✅ Exit status tracking (`$?`)

**Redirections:**
- ✅ Input redirection (`<`)
- ✅ Output redirection (`>`)
- ✅ Append mode (`>>`)
- ✅ Heredoc (`<<`) with variable expansion and Ctrl+C/Ctrl+D handling

**Pipes:**
- ✅ Single pipes (`cmd1 | cmd2`)
- ✅ Multiple pipes (`cmd1 | cmd2 | cmd3 | ...`)
- ✅ Pipes with redirections

**Quote Handling:**
- ✅ Single quotes (`'`) - no expansion
- ✅ Double quotes (`"`) - variable expansion enabled

**Variable Expansion:**
- ✅ Environment variables (`$VAR`, `$HOME`, `$USER`)
- ✅ Exit status (`$?`)
- ✅ Multiple variables in same string

**Built-in Commands:**
- `echo` with `-n` option
- `cd` with relative/absolute paths and `cd -`
- `pwd` (print working directory)
- `export` (set environment variables)
- `unset` (remove environment variables)
- `env` (display environment)
- `exit` with numeric exit codes

---

## 🛠️ Instructions

### Prerequisites

- **Compiler:** GCC or Clang
- **Make:** GNU Make
- **Library:** readline (`libreadline-dev` on Ubuntu/Debian)

### Compilation
```bash
# Clone the repository
git clone [REPOSITORY_URL]
cd minishell

# Compile the project
make
```

### Execution
```bash
# Run the shell
./minishell
```

### Available Make Commands
```bash
make           # Compile the project
make clean     # Remove object files
make fclean    # Remove object files and executable
make re        # Rebuild everything from scratch
make leaks     # Run with Valgrind to detect memory leaks
```

### Usage Examples
```bash
minishell> echo "Hello, World!"
Hello, World!

minishell> export MY_VAR=42
minishell> echo "The answer is $MY_VAR"
The answer is 42

minishell> ls -la | grep minishell | wc -l
5

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

### Testing

**Manual Testing:**
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

# Built-ins
cd /tmp
pwd
cd -
exit 0
```

**Memory Leak Verification:**
```bash
# With Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./minishell

# Or simply
make leaks
```

---

## 📚 Resources

### Classic References

**Official Documentation:**
- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/) - Official bash reference
- [Unix System Calls](https://man7.org/linux/man-pages/) - System calls manual
- [Process Control (GNU libc)](https://www.gnu.org/software/libc/manual/html_node/Process-Control.html) - Process management

**Tutorials and Articles:**
- [Building a Simple Shell](https://brennan.io/2015/01/16/write-a-shell-in-c/) - Tutorial on shell creation
- [Unix Processes](https://www.geeksforgeeks.org/processes-in-linuxunix/) - Unix processes explained
- [File Descriptors](https://www.bottomupcs.com/file_descriptors.xhtml) - File descriptors in detail
- [Pipex Tutorial](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901) - Pipeline implementation guide

**42 Resources:**
- [42 Docs - Minishell](https://harm-smits.github.io/42docs/projects/minishell) - Project documentation
- [42 Cursus](https://github.com/42cursus) - Reference repositories

### AI Usage

**Claude (Anthropic) was used as a development assistant

**Note:** All code was reviewed, tested, and understood by the authors before integration. AI was used as a support tool, not as a substitute for learning.

**42 School | Common Core | 2026**