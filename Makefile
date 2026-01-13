# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 18:14:51 by bfernan2          #+#    #+#              #
#    Updated: 2026/01/13 19:09:11 by malcosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = minishell

SRC = main.c

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
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