/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:02:53 by bfernan2          #+#    #+#             */
/*   Updated: 2026/01/17 16:35:06 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minishell.h"

t_env    *init_env(char **envp)
{
    t_env   *env_new_list;
    t_env    *new_node;
    int     i;
    char    **name_value;
    
    env_new_list = NULL;
    i = 0;
    while (envp[i])
    {
        name_value = ft_split(envp[i], '=');
        new_node = create_env_node(name_value[0], name_value[1]);
        if (!new_node)
            return (NULL);
        add_env_back(&env_new_list, new_node);
        i++;
        free(name_value);
    }
    return (env_new_list);
}