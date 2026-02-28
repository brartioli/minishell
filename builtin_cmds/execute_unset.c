/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:08:03 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/28 16:06:35 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_env_node(t_env **env_list, char *name)
{
	t_env	*current;
	t_env	*prev;

	if (!env_list || !*env_list)
		return ;
	current = *env_list;
	prev = NULL;
	while (current)
	{
		if (ft_str_equal(current->name, name))
			break ;
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev)
		prev->next = current->next;
	else
		*env_list = current->next;
	free(current->name);
	free(current->value);
	free(current);
}

int	ft_execute_unset(t_mini *mini, t_cmd *cmd)
{
	int	i;

	i = 1;
	if (!cmd->args[i])
		return (0);
	while (cmd->args[i])
	{
		if (ft_strchr(cmd->args[i], '='))
		{
			i++;
			continue;
		}
		remove_env_node (&mini->env_list, cmd->args[i]);
		i++;
	}
	return (0);
}
