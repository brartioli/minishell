/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:54:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 20:25:35 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
