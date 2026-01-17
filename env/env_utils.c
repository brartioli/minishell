/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:43:53 by bfernan2          #+#    #+#             */
/*   Updated: 2026/01/17 16:24:18 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "minishell.h"

void    add_env_back(t_env **env_list, t_env *new_env)
{
    t_env   *tmp;
    
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

t_env    *create_env_node(char *name, char *value)
{

    t_env   *new_node;

    new_node = malloc(sizeof(t_env));
    if (!new_node)
        return (NULL);
    new_node->name = name;
    new_node->value = value;
    new_node->next = NULL;
    return(new_node);
}