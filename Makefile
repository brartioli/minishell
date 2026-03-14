# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 18:14:51 by bfernan2          #+#    #+#              #
#    Updated: 2026/03/14 16:46:03 by bfernan2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = minishell

VALGRIND = valgrind -s -q \
			--track-origins=yes \
			--show-leak-kinds=all \
			--track-fds=yes \
			--suppressions=readline.supp \
			--leak-check=full

SRC = main.c clean.c \
tokenize/token_utils.c tokenize/tokenize.c tokenize/split_cmd.c\
env/env.c env/env_utils.c \
path_cmds/exec.c \
path_cmds/execute_simple_command.c \
path_cmds/execute_pipeline.c \
path_cmds/execute_pipeline_utils.c \
path_cmds/get_path.c \
path_cmds/redirects.c \
builtin_cmds/builtins.c \
builtin_cmds/execute_pwd.c \
builtin_cmds/execute_env.c \
builtin_cmds/exit_utils.c \
builtin_cmds/execute_exit.c \
builtin_cmds/execute_export.c \
builtin_cmds/export_utils.c \
parsing/parser.c \
parsing/heredoc.c \
parsing/extracting.c \
parsing/build_args.c \
parsing/pipeline_parsing.c \
parsing/expand.c \
parsing/expand_utils.c \
parsing/process_quotes.c \
parsing/build_args_utils.c \
builtin_cmds/execute_echo.c\
builtin_cmds/execute_unset.c\
builtin_cmds/execute_cd.c\
signals/signals.c\

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
READLINE = -lreadline

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(READLINE) -o $(NAME)
	@echo "\033[0;32m✅ Compiled successfully!\033[0m"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR) all

clean:
	@rm -f $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

readline.supp:
	@echo "{" > readline.supp
	@echo "   ignore_libreadline" >> readline.supp
	@echo "   Memcheck:Leak" >> readline.supp
	@echo "   ..." >> readline.supp
	@echo "   obj:*/libreadline.so.*" >> readline.supp
	@echo "}" >> readline.supp

leaks: readline.supp $(NAME)
	@$(VALGRIND) ./$(NAME)

fclean: clean
	@rm -f $(NAME)
	@rm -f readline.supp
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re leaks