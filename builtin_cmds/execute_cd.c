/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:21 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/12 18:40:47 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//criar função que atualiza o pwd

int	ft_execute_cd(t_mini *mini, t_cmd *cmd)
{
	char	*path;

	if (!cmd->args[1])
		path = get_env_value(mini->env_list, "HOME");
	else
		path = cmd->args[1];
	if (!path)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (1);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		perror(path);
		return (1);
	}
	update_pwd(mini);
	return (0);
}
