/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 21:04:17 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/12 21:10:22 by malcosta         ###   ########.fr       */
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

void	free_pipes(int **pipes, int cmds_quant)
{
	int	i;

	i = 0;
	while (i < cmds_quant - 1)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}
