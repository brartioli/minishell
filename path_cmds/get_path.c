/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:41:43 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 19:34:26 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_full_path(char *cmd, char **env)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = get_path_from_env(env);
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(split_path);
			return (full_path);
		}	
		free(full_path);
		i++;
	}
	ft_free_split(split_path);
	return (NULL);
}

char	*get_path_from_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}
