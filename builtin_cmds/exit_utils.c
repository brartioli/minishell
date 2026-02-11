/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:49:24 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/07 13:52:59 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_valid_number(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (!(ft_isdigit (str[i]) || str[i] == '+'))
            return (0);
        i++;
    }
    return (1);
}