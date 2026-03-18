/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:41:43 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/17 21:34:23 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_in_paths(char **split_path, char *cmd)
{
	char	*full_path;
	char	*tmp;
	int		i;

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

static char	*get_env_value_path(t_env *env_list, char *key)
{
	while (env_list)
	{
		if (ft_str_equal(env_list->name, key))
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}

char	*get_full_path(char *cmd, t_env *env_list)
{
	char	*path;
	char	**split_path;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	path = get_env_value_path(env_list, "PATH");
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	return (search_in_paths(split_path, cmd));
}
