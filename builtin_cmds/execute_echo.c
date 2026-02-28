/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:43:06 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/28 14:30:09 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_n_flag(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	i = 1;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_execute_echo(t_mini *mini)
{
	t_token	*current;
	int		newline;

	newline = 1;
	current = mini->token_list->next;

	while (current && is_n_flag(current->value))
	{
		newline - 0;
		current = current->next;
	}
	while (current)
	{
		ft_putstr_fd(current->value, 1);
		if(current->next)
			ft_putstr_fd(" ", 1);
		current = current->next;
	}
	if (newline)
		ft_putstr_fd("\n", 1);
	return (0);
}
