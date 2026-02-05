/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:26:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/03 20:34:00 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_bultin(t_token *token_list, t_env **env_list)
{
	char	*cmd;
	
	if (!token_list || !token_list->value)
		return (1);

	cmd = token_list->value;
    (void)env_list;
	// if (ft_str_equal(cmd, "echo"))
	// 	return (ft_execute_echo(token_list));
	if (ft_str_equal(cmd, "pwd"))
		return (ft_execute_pwd());
	// else if (ft_str_equal(cmd, "cd"))
	// 	return (ft_execute_cd(token_list, env_list));
	else if (ft_str_equal(cmd, "env"))
		return (ft_execute_env(*env_list));
	// else if (ft_str_equal(cmd, "export"))
	// 	return (ft_execute_export(token_list, env_list));
	// else if (ft_str_equal(cmd, "unset"))
	// 	return (ft_execute_unset(token_list, env_list));
	// else if (ft_str_equal(cmd, "exit"))
	// 	return (ft_execute_exit(token_list));
	return (1);
}