/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:16 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/25 10:25:00 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**parse_input()
{

}

t_cmd	*parse_command(t_token *token_list)
{
	t_cmd	*cmd;

	cmd = init_command(token_list);
	if (!cmd)
		return (NULL);
	process_quotes(token_list);
	expand_variables(token_list);

	cmd->infile = extract_infile(token_list);
	cmd->outfile = extract_outfile(token_list);
	cmd->append = extract_has_append(token_list);
	cmd->args = extract_args(token_list);
}


t_cmd	*init_command(t_token *token_list)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->append = 0;
	return (cmd);
}