/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:30:24 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/19 21:23:48 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_heredoc_warning(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document delimited ", 2);
	ft_putstr_fd("by end-of-file (wanted `", 2);
	ft_putstr_fd(delimiter, 2);
	ft_putstr_fd("')\n", 2);
}

static void	process_heredoc_line(char *line, int pipefd, t_env *env_list,
	int exit_status)
{
	char	*expanded;

	expanded = expand_token(line, env_list, exit_status);
	ft_putstr_fd(expanded, pipefd);
	ft_putstr_fd("\n", pipefd);
	free(expanded);
}

static int	handle_heredoc_interrupt(char *line, int *pipefd)
{
	extern int	g_in_command;

	if (g_in_command == 130)
	{
		if (line)
			free(line);
		close(pipefd[1]);
		close(pipefd[0]);
		g_in_command = 0;
		return (1);
	}
	if (!line)
		return (0);
	return (-1);
}

int	handle_heredoc(char *delimiter, t_env *env_list, int exit_status)
{
	int			pipefd[2];
	char		*line;
	int			interrupt;
	extern int	g_in_command;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	g_in_command = 2;
	while (1)
	{
		line = readline("> ");
		interrupt = handle_heredoc_interrupt(line, pipefd);
		if (interrupt == 1)
			return (-1);
		if (interrupt == 0)
		{
			print_heredoc_warning(delimiter);
			close(pipefd[1]);
			g_in_command = 0;
			return (pipefd[0]);
		}
		if (ft_str_equal(line, delimiter))
		{
			free(line);
			g_in_command = 0;
			close(pipefd[1]);
			return (pipefd[0]);
		}
		process_heredoc_line(line, pipefd[1], env_list, exit_status);
		free(line);
	}
}