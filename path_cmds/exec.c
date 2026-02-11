/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:48:06 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 18:51:01 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_token *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !cmd->value)
		exit (1);
	args = build_args(cmd);
	if (!args)
		exit (1);
	path = get_full_path(args[0], envp);
	if (!path)
	{
		ft_printf("%s: command not found\n", args[0]);
		free_args(args);
		exit (127);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	free_args(args);
	exit(1);
}
