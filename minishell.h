/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:18:52 by bfernan2          #+#    #+#             */
/*   Updated: 2026/01/17 13:47:55 by malcosta         ###   ########.fr       */
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
# define TYPE_CMD "CMD"
# define TYPE_ARG "ARG"
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

// Functions


#endif