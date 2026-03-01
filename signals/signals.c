/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:58:33 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/01 20:09:09 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_in_command = 0;

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	if (!g_in_command)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_sigquit(int sig)
{
	(void)sig;
}

void setup_signals(void)
{
	signal(SIGINT, handle_sigint);
}