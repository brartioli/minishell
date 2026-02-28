/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:37:16 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/28 12:19:11 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**parse_input(t_token *token_list)
{
	t_cmd	**cmds;
	t_token	**token_groups;
	int		cmd_count;
	int		i;

	cmd_count = count_commands(token_list);
	token_groups = split_commands_by_pipe(token_list, cmd_count);
	cmds = malloc(sizeof(t_cmd *) * (cmd_count + 1));
	if (!cmds)
		return (NULL);
	i = 0;
	while (i < cmd_count)
	{
		cmds[i] = parse_command(token_groups[i]);
		i++;
	}
	cmds[i] = NULL;
	free(token_groups);
	return (cmds);
}

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

int	has_redirect(t_cmd *cmd)
{
	if (!cmd)
		return (0);

	if (cmd->infile || cmd->outfile)
		return (1);
	return (0);
}
