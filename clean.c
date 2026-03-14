/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:43:26 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/14 16:48:59 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_all(t_mini *mini)
{
	if (mini->current_cmd)
		free_cmd(mini->current_cmd);
	if (mini->token_list)
		free_token_list(mini->token_list);
	if (mini->env_list)
		free_env_list(mini->env_list);
	rl_clear_history();
}
