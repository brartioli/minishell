/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:23:21 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/12 19:47:04 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cd_path(t_mini *mini, t_cmd *cmd)
{
	char	*path;

	if (!cmd->args[1])
		return (get_env_value(mini->env_list, "HOME"));
	if (ft_str_equal(cmd->args[1], "-"))
	{
		path = get_env_value(mini->env_list, "OLDPWD");
		if (!path)
		{
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
			return (NULL);
		}
		ft_putendl_fd(path, 1);
		return (path);
	}
	return (cmd->args[1]);
}

int	ft_execute_cd(t_mini *mini, t_cmd *cmd)
{
	char	*path;

	path = get_cd_path(mini, cmd);
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

void	update_pwd(t_mini *mini)
{
	char	*old_pwd;
	char	cwd[1024];

	old_pwd = get_env_value(mini->env_list, "PWD");
	if (old_pwd)
		add_or_update_env(mini, "OLDPWD", old_pwd);
	if (getcwd(cwd, sizeof(cwd)))
		add_or_update_env(mini, "PWD", cwd);
}
