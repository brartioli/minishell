/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:16 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/27 14:42:32 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_cmd	**parse_input(t_token *token_list)
// {

// }

t_cmd	*parse_command(t_token *token_list)
{
	t_cmd	*cmd;

	cmd = init_command();
	if (!cmd)
		return (NULL);
	// process_quotes(token_list);
	// expand_variables(token_list);

	cmd->infile = extract_infile(token_list);
	cmd->outfile = extract_outfile(token_list);
	cmd->append = has_append_flag(token_list);
	cmd->args = build_args(token_list);

	return (cmd);
}


t_cmd	*init_command(void)
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

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (!cmd)
		return ;
	if (cmd->args)
	{
		i = 0;
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
	}
	if (cmd->infile)
		free(cmd->infile);
	if (cmd->outfile)
		free(cmd->outfile);
	free(cmd);
}