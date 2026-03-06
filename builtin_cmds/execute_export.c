/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:29:46 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/06 20:42:21 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute_export(t_mini *mini, t_cmd *cmd)
{
	int	i;

	i = 1;
	if (!cmd->args[1])
	{
		print_export(mini->env_list);
		return (0);
	}
	while (cmd->args[i])
	{
		process_export_arg(mini, cmd->args[i]);
		i++;
	}
	return (0);
}

void	print_export(t_env *env_list)
{
	t_env	*ptr;

	ptr = env_list;
	while (ptr)
	{
		if (ptr->value)
			ft_printf("declare -x %s=\"%s\"\n", ptr->name, ptr->value);
		else
			ft_printf("declare -x %s\n", ptr->name);
		ptr = ptr->next;
	}
}

void	process_export_arg(t_mini *mini, char *arg)
{
	char	*name;
	char	*value;

	split_var_value(arg, &name, &value);
	if (!is_valid_identifier(name))
	{
		ft_printf("export: `%s': not a valid identifier\n", arg);
		free(name);
		free(value);
		return ;
	}
	add_or_update_env(mini, name, value);
	free(name);
	free(value);
}
