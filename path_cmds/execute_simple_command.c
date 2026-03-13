/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/12 21:12:26 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_child_process(t_cmd *cmd, t_mini *mini, char **new_envp)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	apply_redirects(cmd);
	if (ft_is_builtin(cmd->args[0]))
		exit(ft_execute_builtin(mini, cmd));
	else
		ft_exec(cmd, new_envp);
}

static void	handle_parent_process(pid_t pid, t_mini *mini)
{
	int			exit_status;
	extern int	g_in_command;

	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		mini->exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		mini->exit_status = 128 + WTERMSIG(exit_status);
	g_in_command = 0;
}

void	ft_execute_simple_command(t_cmd *cmd, t_mini *mini)
{
	pid_t		pid;
	char		**new_envp;
	extern int	g_in_command;

	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	new_envp = env_list_to_array(mini->env_list);
	g_in_command = 1;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		g_in_command = 0;
		free_array(new_envp);
		return ;
	}
	if (pid == 0)
		handle_child_process(cmd, mini, new_envp);
	else
		handle_parent_process(pid, mini);
	free_array(new_envp);
}
