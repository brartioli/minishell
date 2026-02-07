/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:31 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/07 12:05:16 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_commands(t_token *token_list)
{
	int	count;

	count = 1;
	while (token_list)
	{
		if (ft_str_equal(token_list->value, "|"))
			count++;
		token_list = token_list->next;
	}
	return (count);
}