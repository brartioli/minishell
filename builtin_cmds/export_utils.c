/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:38:53 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/06 20:45:36 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_var_value(char *arg, char **name, char **value)
{
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	if (equal_pos)
	{
		*name = ft_substr(arg, 0, equal_pos - arg);
		*value = ft_strdup(equal_pos + 1);
	}
	else
	{
		*name = ft_strdup(arg);
		*value = NULL;
	}
}

int	is_valid_identifier(char *name)
{
	int	i;

	if (!name || !*name)
		return (0);
	if (!ft_isalpha(name[0]) && name[0] != '_')
		return (0);
	i = 1;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	add_or_update_env(t_mini *mini, char *name, char *value)
{
	t_env	*ptr;
	t_env	*new;
	char	*new_value;

	ptr = mini->env_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->name, name))
		{
			if (value)
			{
				free(ptr->value);
				ptr->value = ft_strdup(value);
			}
			return ;
		}
		ptr = ptr->next;
	}
	if (value)
		new_value = ft_strdup(value);
	else
		new_value = NULL;
	new = create_env_node(ft_strdup(name), new_value);
	add_env_back(&mini->env_list, new);
}
