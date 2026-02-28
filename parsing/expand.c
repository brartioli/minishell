/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:21:47 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/28 16:20:31 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_variables(t_token *token_list, t_env *env_list, int exit_status)
{
	t_token	*ptr;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_WORD))
		{
			if (ft_strchr(ptr->value, '$'))
			{
				
			}
		}
		ptr = ptr->next;
	}
}

char	*get_env_value(t_env *env_list, char *var_name)
{
	t_env	*ptr;

	ptr = env_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->name, var_name))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

char	*expand_token(char *str, t_env *env_list, int exit_status)
{
	char	*dollar_pos;
	char	*var_name;
	char	*var_value;
	char	*result;

	dollar_pos = ft_strchar(str, '$');
	if (!dollar_pos)
		return (ft_strdup(str));
	if (dollar_pos[1] == '?')
	{
		var_value = ft_itoa(exit_status);
		// TO DO: MONTAR RESULTDO
	}
	return (result);
}
