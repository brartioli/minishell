/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:48:06 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/01 17:46:21 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_cmd *cmd, char **envp)
{
	char	*path;

	if (!cmd || !cmd->args || !cmd->args[0])
		exit (1);
	path = get_full_path(cmd->args[0], envp);
	if (!path)
	{
		ft_printf("%s: command not found\n", cmd->args[0]);
		//free_args(args);
		exit(127);
	}
	execve(path, cmd->args, envp);
	perror("execve");
	free(path);
	exit(1);
}
