/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:58:33 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/19 21:23:25 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_in_command = 0;

void	handle_sigint(int sig)
{
	(void)sig;
	if (g_in_command == 2)
	{
		g_in_command = 130;
		write(1, "\n", 1);
		rl_done = 1;
		return ;
	}
	write(1, "\n", 1);
	if (g_in_command == 0)
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

void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
