/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:26:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/19 17:54:53 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_builtin(t_mini *mini, t_cmd *cmd)
{
	char	*cmd_name;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (1);
	cmd_name = cmd->args[0];
	if (ft_str_equal(cmd_name, "pwd"))
		return (ft_execute_pwd());
	else if (ft_str_equal(cmd_name, "env"))
		return (ft_execute_env(mini, cmd));
	else if (ft_str_equal(cmd_name, "exit"))
		return (ft_execute_exit(mini));
	else if (ft_str_equal(cmd_name, "echo"))
		return (ft_execute_echo(cmd));
	else if (ft_str_equal(cmd_name, "unset"))
		return (ft_execute_unset(mini, cmd));
	else if (ft_str_equal(cmd_name, "export"))
		return (ft_execute_export(mini, cmd));
	else if (ft_str_equal(cmd_name, "cd"))
		return (ft_execute_cd(mini, cmd));
	else
		return (1);
}

int	ft_is_builtin(char *cmd)
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
	if (ft_str_equal(cmd, "export"))
		return (1);
	return (0);
}
