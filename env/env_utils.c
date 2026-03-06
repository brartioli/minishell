/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:43:53 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/06 20:50:08 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_env_back(t_env **env_list, t_env *new_env)
{
	t_env	*tmp;

	if (!env_list || !new_env)
		return ;
	if (!*env_list)
	{
		*env_list = new_env;
		return ;
	}
	tmp = *env_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_env;
}

t_env	*create_env_node(char *name, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->name = name;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

static char	*create_env_line(t_env *node)
{
	char	*temp;
	char	*line;
	char	*value;

	temp = ft_strjoin(node->name, "=");
	if (node->value)
		value = node->value;
	else
		value = "";
	line = ft_strjoin(temp, value);
	free(temp);
	return (line);
}

char	**env_list_to_array(t_env *env_list)
{
	char	**envp;
	t_env	*ptr;
	int		count;
	int		i;

	count = 0;
	ptr = env_list;
	while (ptr && ++count)
		ptr = ptr->next;
	envp = malloc(sizeof(char *) * (count + 1));
	if (!envp)
		return (NULL);
	ptr = env_list;
	i = 0;
	while (ptr)
	{
		envp[i++] = create_env_line(ptr);
		ptr = ptr->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
