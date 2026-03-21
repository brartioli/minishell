/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:37:29 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/21 13:46:36 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

int	check_pipe_syntax(char *cmd_line)
{
	int	i;

	i = 0;
	while (cmd_line[i] == ' ')
		i++;
	if (cmd_line[i] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	i = ft_strlen(cmd_line) - 1;
	while (i >= 0 && cmd_line[i] == ' ')
		i--;
	if (i >= 0 && cmd_line[i] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}
