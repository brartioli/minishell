/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:49:02 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/01 18:49:22 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void process_quotes(t_token *token_list)
{
    t_token *ptr;
    char    *new_value;
    int     len;

    ptr = token_list;
    while (ptr)
    {
        if (ft_str_equal(ptr->type, TYPE_WORD))
        {
            len = ft_strlen(ptr->value);
            
            // Se começa e termina com aspas (simples ou duplas)
            if (len >= 2 && 
                ((ptr->value[0] == '"' && ptr->value[len - 1] == '"') ||
                 (ptr->value[0] == '\'' && ptr->value[len - 1] == '\'')))
            {
                new_value = ft_substr(ptr->value, 1, len - 2);
                free(ptr->value);
                ptr->value = new_value;
            }
        }
        ptr = ptr->next;
    }
}