/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:26:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/26 21:13:09 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_builtin(t_mini *mini, t_cmd *cmd)
{
	char	*cmd_name;
	
	if (!cmd || !cmd->args || !cmd->args[0])
		return (1);
	cmd_name = cmd->args[0];
	// if (ft_str_equal(cmd_name, "echo"))
	// 	return (ft_execute_echo(cmd));
	if (ft_str_equal(cmd_name, "pwd"))
		return (ft_execute_pwd());
	// else if (ft_str_equal(cmd_name, "cd"))
	// 	return (ft_execute_cd(cmd, env_list));
	else if (ft_str_equal(cmd_name, "env"))
		return (ft_execute_env(mini));
	// else if (ft_str_equal(cmd_name, "export"))
	// 	return (ft_execute_export(cmd, env_list));
	// else if (ft_str_equal(cmd_name, "unset"))
	// 	return (ft_execute_unset(cmd, env_list));
	else if (ft_str_equal(cmd_name, "exit"))
		return (ft_execute_exit(mini));
	return (1);
}
