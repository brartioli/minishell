/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:42:10 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/11 19:37:13 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_env(t_mini *mini)
{
    t_env   *tmp;

    if (mini->token_list->next)
    {
        ft_putendl_fd("env: too many arguments", 2);
        return (1);
    }
	if (!mini || !mini->env_list)
        return (0);
    tmp = mini->env_list;
    while (tmp)
    {
        if (tmp->value)
            ft_printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
    return (0);
}
