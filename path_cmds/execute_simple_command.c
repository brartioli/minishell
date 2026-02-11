/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 19:34:08 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_simple_command(t_token *token_list, char **envp)
{
	pid_t	pid;

	if (!token_list || !token_list->value)
		return ;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
		ft_exec(token_list, envp);
	else
		waitpid(pid, NULL, 0);
}
