/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:27:42 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/17 21:06:38 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_exit_args(t_token *token_list)
{
	int		count;
	t_token	*current;

	count = 0;
	current = token_list->next;
	while (current && ++count)
		current = current->next;
	return (count);
}

static int	exit_with_arg(t_mini *mini)
{
	char	*arg;
	int		exit_code;

	arg = mini->token_list->next->value;
	if (!is_valid_number(arg))
	{
		ft_printf("minishell: exit: %s: numeric argument required\n", arg);
		cleanup_all(mini);
		exit(2);
	}
	exit_code = ft_atoi(arg);
	cleanup_all(mini);
	exit(exit_code % 256);
}

int	ft_execute_exit(t_mini *mini)
{
	int	count_args;

	ft_printf("exit\n");
	count_args = count_exit_args(mini->token_list);
	if (count_args == 0)
	{
		cleanup_all(mini);
		exit(mini->exit_status);
	}
	if (count_args > 1)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (1);
	}
	return (exit_with_arg(mini));
}
