/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:27:42 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/11 20:02:28 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_exit(t_mini	*mini)
{
	int		count_args;
	t_token	*current;
	char	*arg;

	ft_printf("exit\n");
	count_args = 0;
	current = mini->token_list->next;
	while (current && ++count_args) 
		current = current->next;
	if (count_args == 0)
		exit (mini->exit_status);
	else if (count_args > 1)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	arg = mini->token_list->next->value;
	if (!is_valid_number(arg))
	{
		ft_printf("minishell: exit: %s: numeric argument required\n", arg);
		exit(255);
	}
	exit(ft_atoi(arg) % 256);
}
