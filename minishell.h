/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:18:52 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/03 20:36:52 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include "libft/libft.h"

// Define token types
# define TYPE_WORD "WORD"
# define TYPE_PIPE "PIPE"


// Structs
typedef struct s_token
{
	char	*value;
	char	*type;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;


typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env	*next;
}	t_env;

// FUNCTIONS

// Tokens
void	init_token_list(t_token **token_list, char *cmd_line);
t_token	*create_token(char *value, char *type);
void	add_token_back(t_token **token_list, t_token *new_token);
void	print_token_list(t_token *token_list);
void	free_token_list(t_token *token_list);

//env
t_env    *init_env(char **envp);
void    add_env_back(t_env **env_list, t_env *new_env);
t_env    *create_env_node(char *name, char *value);

//builtin
int	ft_execute_bultin(t_token *token_list, t_env **env_list);
int ft_execute_pwd(void);
int ft_execute_env(t_env *env_list);
//path
void	ft_execute_path(t_token *token_list, t_env *env_list);
char	*get_full_path(char *cmd, t_env *env_list);
char *get_path_from_env(t_env *env_list);


#endif