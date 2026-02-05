/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:27:42 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/03 20:41:13 by bfernan2         ###   ########.fr       */
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