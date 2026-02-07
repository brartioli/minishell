/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/07 11:12:27 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_builtin(char *cmd)
{
	if (ft_str_equal(cmd, "echo"))
		return (1);
	if (ft_str_equal(cmd, "pwd"))
		return (1);
	if (ft_str_equal(cmd, "cd"))
		return (1);
	if (ft_str_equal(cmd, "unset"))
		return (1);
	if (ft_str_equal(cmd, "env"))
		return (1);
	if (ft_str_equal(cmd, "exit"))
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env_list;
	t_token	*token_list;
	char	*cmd_line;

	(void)argc;
	(void)argv;
	env_list = NULL;
	env_list = init_env(envp);
	while (1)
	{
		token_list = NULL;
		cmd_line = readline("minishell> ");
		if (ft_str_equal(cmd_line, "exit") == 1)
			break ;
		else
		{
			init_token_list(&token_list, cmd_line);
			if (ft_is_builtin(token_list->value))
			{
				ft_execute_bultin(token_list, &env_list);
			}
			else
			{
				ft_execute_path(token_list, envp);
			}
		}
		free_token_list(token_list);
		free(cmd_line);
	}
	return (0);
}
