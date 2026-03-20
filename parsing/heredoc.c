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

static void	process_heredoc_line(char *line, int pipefd, t_env *env_list,
	int exit_status)
{
	char	*expanded;

	expanded = expand_token(line, env_list, exit_status);
	ft_putstr_fd(expanded, pipefd);
	ft_putstr_fd("\n", pipefd);
	free(expanded);
}

static int	handle_heredoc_interrupt(char *line, int *pipefd, int saved_fd)
{
	extern int	g_in_command;

	if (g_in_command == 130)
	{
		if (line)
			free(line);
		close(pipefd[1]);
		close(pipefd[0]);
		dup2(saved_fd, STDIN_FILENO);
		close(saved_fd);
		return (-2);
	}
	if (!line)
		return (0);
	return (-1);
}

static int	check_heredoc_end(char *line, char *delim, int *pipefd)
{
	extern int	g_in_command;

	if (!line)
	{
		ft_putstr_fd("minishell: warning: here-document delimited ", 2);
		ft_putstr_fd("by end-of-file (wanted `", 2);
		ft_putstr_fd(delim, 2);
		ft_putstr_fd("')\n", 2);
		close(pipefd[1]);
		g_in_command = 0;
		return (pipefd[0]);
	}
	if (ft_str_equal(line, delim))
	{
		free(line);
		g_in_command = 0;
		close(pipefd[1]);
		return (pipefd[0]);
	}
	return (-1);
}

int	handle_heredoc(char *delimiter, t_env *env_list, int exit_status)
{
	int			pipefd[2];
	char		*line;
	int			result;
	extern int	g_in_command;
	int			saved_stdin;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	saved_stdin = dup(STDIN_FILENO);
	g_in_command = 2;
	while (1)
	{
		line = readline("> ");
		result = handle_heredoc_interrupt(line, pipefd, saved_stdin);
		if (result == -2)
			return (-2);
		result = check_heredoc_end(line, delimiter, pipefd);
		if (result >= 0)
			return (close(saved_stdin), result);
		process_heredoc_line(line, pipefd[1], env_list, exit_status);
		free(line);
	}
}
