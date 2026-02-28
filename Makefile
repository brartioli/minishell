# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 18:14:51 by bfernan2          #+#    #+#              #
#    Updated: 2026/02/28 15:14:24 by bfernan2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = minishell

SRC = main.c tokenize/token_utils.c tokenize/tokenize.c \
env/env.c env/env_utils.c \
path_cmds/exec.c \
path_cmds/execute_simple_command.c \
path_cmds/execute_pipeline.c \
path_cmds/get_path.c \
path_cmds/redirects.c \
builtin_cmds/builtins.c \
builtin_cmds/execute_pwd.c \
builtin_cmds/execute_env.c \
builtin_cmds/exit_utils.c \
builtin_cmds/execute_exit.c \
parsing/parser.c \
parsing/extracting.c \
parsing/build_args.c \
parsing/pipeline_parsing.c \
builtin_cmds/execute_echo.c\
builtin_cmds/execute_unset.c\

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

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re