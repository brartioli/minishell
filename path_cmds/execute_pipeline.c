/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:31 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 19:38:11 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_pipeline(t_token **cmds, int cmds_quant, char **envp)
{
	int		**pipes;
	pid_t	*pids;
	int		i;

	pipes = create_pipes(cmds_quant);
	if (!pipes)
		return ;
	pids = malloc(sizeof(pid_t) * cmds_quant);
	if (!pids)
		return ;
	i = 0;
	while (i < cmds_quant)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (i > 0)
				dup2(pipes[i - 1][0], STDIN_FILENO);
			if (i < cmds_quant - 1)
				dup2(pipes[i][1], STDOUT_FILENO);
			close_all_pipes(pipes, cmds_quant);
			ft_exec(cmds[i], envp);
		}
		i++;
	}
	close_all_pipes(pipes, cmds_quant);
	wait_all_children(pids, cmds_quant);
}

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

void	wait_all_children(pid_t *pids, int cmds_quant)
{
	int	i;

	i = 0;
	while (i < cmds_quant)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}
