/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:04:17 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/14 15:27:47 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_all_pipes(int **pipes, int cmds_quant)
{
	int	i;

	i = 0;
	while (i < cmds_quant - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	wait_all_children(pid_t *pids, int cmds_quant, t_mini *mini)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmds_quant)
	{
		waitpid(pids[i], &status, 0);
		if (i == cmds_quant - 1)
		{
			if (WIFEXITED(status))
				mini->exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				mini->exit_status = 128 + WTERMSIG(status);
		}
		i++;
	}
}

void	free_pipes(int **pipes, int cmds_quant)
{
	int	i;

	i = 0;
	if (!pipes)
		return ;
	while (i < cmds_quant - 1)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	free_cmds_array(t_cmd **cmds, int cmd_count)
{
	int	i;

	if (!cmds)
		return ;
	i = 0;
	while (i < cmd_count)
	{
		free_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}
