/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:08:57 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 19:57:25 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_token_type(char *token)
{
	if (ft_str_equal(token, "|"))
		return (TYPE_PIPE);
	if (ft_str_equal(token, "<"))
		return (TYPE_REDIR_IN);
	if (ft_str_equal(token, ">"))
		return (TYPE_REDIR_OUT);
	if (ft_str_equal(token, ">>"))
		return (TYPE_REDIR_APPEND);
	if (ft_str_equal(token, "<<"))
		return (TYPE_HEREDOC);
	return (TYPE_WORD);
}

void	init_token_list(t_token **token_list, char *cmd_line)
{
	char	**cmd_line_split;
	t_token	*new_token;
	int		i;
	char	*type;

	cmd_line_split = ft_split(cmd_line, ' ');
	i = 0;
	while (cmd_line_split[i])
	{
		type = get_token_type(cmd_line_split[i]);
		new_token = create_token(cmd_line_split[i], type);
		add_token_back(token_list, new_token);
		i++;
	}
	ft_free_split(cmd_line_split);
}
