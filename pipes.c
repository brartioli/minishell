/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:31 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/07 14:00:44 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_commands(t_token *token_list)
{
	int	count;

	count = 1;
	while (token_list)
	{
		if (ft_str_equal(token_list->type, TYPE_PIPE))
			count++;
		token_list = token_list->next;
	}
	return (count);
}

t_token	**split_commands_by_pipe(t_token *token_list, int cmds_quant)
{
	t_token	**cmds;
	int		i;

	cmds = malloc(sizeof(t_token *) * (cmds_quant + 1));
	if (!cmds)
		return (NULL);
	i = 0;
	cmds[i] = token_list;
	while (token_list)
	{
		if (ft_str_equal(token_list->type, TYPE_PIPE))
		{
			token_list->value = NULL;
			i++;
			cmds[i] = token_list->next;
		}
		token_list = token_list->next;
	}
	cmds[i + 1] = NULL;
	return (cmds);
}

int	**create_pipes(int cmds_quant)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * (cmds_quant - 1));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < cmds_quant - 1)
	{
		pipes[i] = malloc(sizeof(int) * 2); 
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

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
			exec_pipes(cmds[i], envp);
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

void	exec_pipes(t_token *cmd, char **envp)
{
	char	**args;
	char	*path;
	args = build_args(cmd);
	if (!args)
		exit (1);
	path = get_full_path(args[0], envp);
	if (!path)
	{
		ft_printf("%s: command not found\n", args[0]);
		free_args(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	exit(1);
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