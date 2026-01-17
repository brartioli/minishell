/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:08:57 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/17 14:46:22 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_token_list(t_token **token_list, char *cmd_line)
{
	char **cmd_line_split;
	t_token	*new_token;
	int	i;
	char	*type;

	cmd_line_split = ft_split(cmd_line, ' ');
	i = 0;
	while (cmd_line_split[i])
	{
		type = TYPE_WORD;
		if (ft_str_equal(cmd_line_split[i], "|"))
			type = TYPE_PIPE;
		new_token = create_token(cmd_line_split[i], type);
		add_token_back(token_list, new_token);
		i++;
	}
}
