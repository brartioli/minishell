/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/01 20:09:36 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_simple_command(t_cmd *cmd, char **envp, t_mini *mini)
{
	pid_t		pid;
	int			exit_status;
	extern int	g_in_command;

	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	g_in_command = 1;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		g_in_command = 0;
		return ;
	}
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		apply_redirects(cmd);
		if (ft_is_builtin(cmd->args[0]))
			exit(ft_execute_builtin(mini, cmd));
		else
			ft_exec(cmd, envp);
	}
	else
	{
		waitpid(pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			mini->exit_status = WEXITSTATUS(exit_status);
		else if (WIFSIGNALED(exit_status))
			mini->exit_status = 128 + WTERMSIG(exit_status);
	g_in_command = 0;
	}
}
