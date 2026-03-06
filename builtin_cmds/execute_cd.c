/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:21 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/06 16:14:59 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_cd(t_mini *mini, t_cmd *cmd)
{
	char *path;
	
	if (!cmd->args[1])
		path = get_env_value(mini->env_list, "HOME");
	else if (ft_str_equal(cmd->args[1], "-"))
	{
		path = get_env_value(mini->env_list, "OLDPWD");
		if (!path)
		{
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
			return (1);
		}
		ft_putendl_fd(path, 1);
	}
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

void update_pwd(t_mini *mini)
{
	char *old_pwd;
	char cwd[1024];
	
	old_pwd = get_env_value(mini->env_list, "PWD");
	
	if (old_pwd)
		add_or_update_env(mini, "OLDPWD", old_pwd);
	
	if (getcwd(cwd, sizeof(cwd)))
		add_or_update_env(mini, "PWD", cwd);
}