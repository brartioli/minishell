/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:26:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/27 16:09:03 by malcosta         ###   ########.fr       */
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
	return (1);
}