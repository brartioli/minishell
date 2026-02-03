/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:27:42 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/03 19:27:53 by bfernan2         ###   ########.fr       */
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