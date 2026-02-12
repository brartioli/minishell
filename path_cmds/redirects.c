/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:22:38 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/12 18:18:07 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_execute_redir_in(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (dup2(fd, 0) == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	ft_execute_redir_out(char *file_name)
{
	int	fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	if (dup2(fd, 1) == -1)
		return (-1);
	close(fd);
	return (0);
}

static int	ft_execute_redir_append(char *file_name)
{
	int	fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (-1);
	if (dup2(fd, 1) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	handle_redirects(t_token *token_list)
{
	t_token	*ptr;
	char	*file_name;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_REDIR_IN))
		{
			if (!ptr->next || !ptr->next->value)
				return (-1);
			file_name = ptr->next->value;
			if (ft_execute_redir_in(file_name) == -1)
				return (-1);
		}
		else if (ft_str_equal(ptr->type, TYPE_REDIR_OUT))
		{
			if (!ptr->next || !ptr->next->value)
				return (-1);
			file_name = ptr->next->value;
			if (ft_execute_redir_out(file_name) == -1)
				return (-1);
		}
		else if (ft_str_equal(ptr->type, TYPE_REDIR_APPEND))
		{
			if (!ptr->next || !ptr->next->value)
				return (-1);
			file_name = ptr->next->value;
			if (ft_execute_redir_append(file_name) == -1)
				return (-1);
		}
		ptr = ptr->next;
	}
	return (0);
}

