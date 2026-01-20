/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:18:34 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/20 20:06:42 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*create_token(char *value, char *type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	token->type = ft_strdup(type);
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

void	add_token_back(t_token **token_list, t_token *new_token)
{
	t_token	*tmp;

	if (!token_list || !new_token)
		return ;
	if (!*token_list)
	{
		*token_list = new_token;
		return ;
	}
	tmp = *token_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_token;
	new_token->prev = tmp;
}

void	print_token_list(t_token *token_list)
{
	while (token_list)
	{
		ft_printf("value: [%s]\n", token_list->value);
		ft_printf("type:  [%s]\n\n", token_list->type);
		token_list = token_list->next;
	}
}

void	free_token_list(t_token *token_list)
{
	t_token	*tmp;

	while (token_list)
	{
		tmp = token_list;
		token_list = token_list->next;
		free(tmp->value);
		free(tmp->type);
		free(tmp);
	}
}
