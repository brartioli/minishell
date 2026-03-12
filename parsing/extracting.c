/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:31:57 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/12 19:36:03 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_infile(t_token *token_list)
{
	t_token	*ptr;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_PIPE))
			break ;
		if (ft_str_equal(ptr->type, TYPE_REDIR_IN))
		{
			if (ptr->next && ptr->next->value)
				return (ft_strdup(ptr->next->value));
		}
		ptr = ptr->next;
	}
	return (NULL);
}

char	*extract_outfile(t_token *token_list)
{
	t_token	*ptr;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_PIPE))
			break ;
		if (ft_str_equal(ptr->type, TYPE_REDIR_OUT)
			|| ft_str_equal(ptr->type, TYPE_REDIR_APPEND))
		{
			if (ptr->next && ptr->next->value)
				return (ft_strdup(ptr->next->value));
		}
		ptr = ptr->next;
	}
	return (NULL);
}

int	has_append_flag(t_token *token_list)
{
	t_token	*ptr;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_PIPE))
			break ;
		if (ft_str_equal(ptr->type, TYPE_REDIR_APPEND))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	extract_heredoc(t_token *token_list)
{
	t_token	*ptr;
	char	*delimiter;
	int		fd;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_HEREDOC))
		{
			if (ptr->next && ptr->next->value)
			{
				delimiter = ptr->next->value;
				fd = handle_heredoc(delimiter);
				return (fd);
			}
		}
		ptr = ptr->next;
	}
	return (-1);
}
