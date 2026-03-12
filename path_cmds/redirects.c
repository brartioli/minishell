/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:22:38 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/12 19:39:40 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	apply_redirects(t_cmd *cmd)
{
	int	fd;

	if (!cmd)
		return ;
	if (cmd->heredoc_fd != -1)
	{
		if (dup2(cmd->heredoc_fd, 0) == -1)
			perror("dup2 heredoc");
		close(cmd->heredoc_fd);
	}
	else if (cmd->infile)
	{
		fd = open(cmd->infile, O_RDONLY);
		if (fd < 0)
		{
			perror(cmd->infile);
			exit(1);
		}
		dup2(fd, 0);
		close(fd);
	}
	if (cmd->outfile)
	{
		if (cmd->append)
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror(cmd->outfile);
			exit(1);
		}
		dup2(fd, 1);
		close(fd);
	}
}
