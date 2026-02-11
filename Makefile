# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 18:14:51 by bfernan2          #+#    #+#              #
#    Updated: 2026/02/11 19:08:04 by malcosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = minishell

SRC = main.c tokenize/token_utils.c tokenize/tokenize.c \
env/env.c env/env_utils.c \
path_cmds/exec.c path_cmds/execute_simple_command.c \
path_cmds/execute_pipeline.c path_cmds/pipeline_utils.c \
path_cmds/build_args.c path_cmds/get_path.c \
builtin_cmds/builtins.c builtin_cmds/execute_builtins.c


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