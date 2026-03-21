/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:31 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/17 21:29:30 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setup_child_pipes(int **pipes, int i, int cmds_quant)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < cmds_quant - 1)
		dup2(pipes[i][1], STDOUT_FILENO);
	close_all_pipes(pipes, cmds_quant);
}

static void	cleanup_pipeline(int **pipes, pid_t *pids,
	int cmds_quant, t_mini *mini)
{
	close_all_pipes(pipes, cmds_quant);
	wait_all_children(pids, cmds_quant, mini);
	free_pipes(pipes, cmds_quant);
	free(pids);
}

static void	init_execute_pipeline(t_mini *mini, char ***new_envp, int ***pipes,
		int cmds_quant)
{
	*new_envp = env_list_to_array(mini->env_list);
	*pipes = create_pipes(cmds_quant);
}

static void	execute_pipeline_child(t_cmd *cmd, char **new_envp, t_mini *mini)
{
	if (ft_is_builtin(cmd->args[0]))
	{
		mini->exit_status = ft_execute_builtin(mini, cmd);
		exit(mini->exit_status);
	}
	else
		ft_exec(cmd, new_envp, mini);
}

void	ft_execute_pipeline(t_cmd **cmds, int cmds_quant, t_mini *mini)
{
	int			**pipes;
	pid_t		*pids;
	char		**new_envp;
	int			i;
	extern int	g_in_command;

	g_in_command = 1;
	init_execute_pipeline(mini, &new_envp, &pipes, cmds_quant);
	pids = malloc(sizeof(pid_t) * cmds_quant);
	if (!pids)
		return (free_pipes(pipes, cmds_quant), free_array(new_envp));
	i = -1;
	while (++i < cmds_quant)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			setup_child_pipes(pipes, i, cmds_quant);
			apply_redirects(cmds[i]);
			execute_pipeline_child(cmds[i], new_envp, mini);
		}
	}
	cleanup_pipeline(pipes, pids, cmds_quant, mini);
	g_in_command = 0;
	return (free_cmds_array(cmds, cmds_quant), free_array(new_envp));
}
