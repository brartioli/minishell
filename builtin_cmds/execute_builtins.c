/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:27:42 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/07 13:59:26 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_execute_pwd(void)
{
    char    *cwd;

    cwd = getcwd(NULL, 0);
    if (!cwd)
    {
        perror("pwd");
        return (1);
    }
    ft_printf("%s\n",cwd);
    free (cwd);
    return (0);
}

int ft_execute_env(t_env **env_list)
{
    t_env   *tmp;

	if (!env_list || !*env_list)
        return (0);
    tmp = *env_list;
    while (tmp)
    {
        if (tmp->value)
            ft_printf("%s=%s\n", tmp->name, tmp->value);
        tmp = tmp->next;
    }
    return (0);
}

int ft_execute_exit(t_token *token_list)
{
	int		count_args;
	t_token	*current;
	char	*arg;

	count_args = 0;
	current = token_list->next;
	while (current && ++count_args) 
		current = current->next;
	if (count_args == 0)
		exit (0);
	else if (count_args > 1)
	return (ft_printf("exit: too many arguments\n"), 1);
	arg = token_list->next->value;
	if (!is_valid_number(arg))
	{
		ft_printf("exit: %s: numeric argument required\n");
		exit(255);
	}
	exit(ft_atoi(arg) % 256);
}