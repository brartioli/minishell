/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/26 21:14:09 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_simple_command(t_cmd *cmd, char **envp)
{
	pid_t	pid;

	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
	{
		apply_redirects(cmd);
		ft_exec(cmd, envp);
	}
	else
		waitpid(pid, NULL, 0);
}
