/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:14:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/12 19:21:48 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_redirect_type(char *type)
{
	if (ft_str_equal(type, TYPE_REDIR_IN))
		return (1);
	if (ft_str_equal(type, TYPE_REDIR_OUT))
		return (1);
	if (ft_str_equal(type, TYPE_REDIR_APPEND))
		return (1);
	if (ft_str_equal(type, TYPE_HEREDOC))
		return (1);
	return (0);
}

int	count_args(t_token *start)
{
	t_token	*current;
	int		count;

	count = 0;
	current = start;
	while (current && !ft_str_equal(current->type, TYPE_PIPE))
	{
		if (ft_str_equal(current->type, TYPE_WORD))
			count++;
		else if (is_redirect_type(current->type))
			current = current->next;
		current = current->next;
	}
	return (count);
}

char	**allocate_args(int count)
{
	char	**args;

	args = malloc(sizeof(char *) * (count + 1));
	return (args);
}

int	fill_args(char **args, t_token *start)
{
	t_token	*current;
	int		i;

	i = 0;
	current = start;
	while (current && !ft_str_equal(current->type, TYPE_PIPE))
	{
		if (ft_str_equal(current->type, TYPE_WORD))
		{
			args[i] = ft_strdup(current->value);
			if (!args[i])
			{
				while (i > 0)
					free(args[--i]);
				return (-1);
			}
			i++;
		}
		else if (is_redirect_type(current->type))
			current = current->next;
		current = current->next;
	}
	args[i] = NULL;
	return (0);
}

char	**build_args(t_token *token_list)
{
	char	**args;
	int		count;

	count = count_args(token_list);
	if (count == 0)
		return (NULL);
	args = allocate_args(count);
	if (!args)
		return (NULL);
	if (fill_args(args, token_list) == -1)
	{
		free(args);
		return (NULL);
	}
	return (args);
}
