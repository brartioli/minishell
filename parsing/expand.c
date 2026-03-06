/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:21:47 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/06 20:33:00 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void expand_variables(t_token *token_list, t_env *env_list, int exit_status)
{
	t_token *ptr;
	char	*new_value;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_WORD))
		{
            if (ptr->value[0] == '\'')
            {
                ptr = ptr->next;
                continue;
            }
            if (ft_strchr(ptr->value, '$'))
            {
                new_value = expand_token(ptr->value, env_list, exit_status);
                free(ptr->value);
                ptr->value = new_value;
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

char *expand_token(char *str, t_env *env_list, int exit_status)
{
	char *dollar_pos;
	char *var_name;
	char *var_value;
	char *result;
	char *temp;
	int  var_len;

	dollar_pos = ft_strchr(str, '$');
	if (!dollar_pos)
		return (ft_strdup(str));
	
	if (dollar_pos[1] == '?')
	{
		var_value = ft_itoa(exit_status);
		var_len = 1;
	}
	else
	{
		var_name = extract_var_name(dollar_pos + 1);
		if (!var_name)
			return (ft_strdup(str));
		var_value = get_env_value(env_list, var_name);
		if (!var_value)
			var_value = "";
		free(var_name);
		var_len = get_var_name_len(dollar_pos + 1);
	}
	
	result = build_expanded_str(str, dollar_pos, var_value, var_len);
	if (dollar_pos[1] == '?')
		free(var_value);
	temp = expand_token(result, env_list, exit_status);
	free(result);
	return (temp);
}

char *build_expanded_str(char *str, char *dollar_pos, char *value, int var_len)
{
	char *before;
	char *after;
	char *temp;
	char *result;

	before = ft_substr(str, 0, dollar_pos - str);
	after = dollar_pos + 1 + var_len;
	temp = ft_strjoin(before, value);
	result = ft_strjoin(temp, after);
	free(before);
	free(temp);
	return (result);
}
