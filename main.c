/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/11 19:59:24 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_builtin(char *cmd)
{
	if (ft_str_equal(cmd, "echo"))
		return (1);
	if (ft_str_equal(cmd, "pwd"))
		return (1);
	if (ft_str_equal(cmd, "cd"))
		return (1);
	if (ft_str_equal(cmd, "unset"))
		return (1);
	if (ft_str_equal(cmd, "env"))
		return (1);
	if (ft_str_equal(cmd, "exit"))
		return (1);
	return (0);
}

static int	has_pipes(t_token *token_list)
{
	t_token	*ptr;

	ptr = token_list;
	while (ptr)
	{
		if (ft_str_equal(ptr->type, TYPE_PIPE))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	ft_execute_commad(t_mini *mini, char **envp)
{
	int	cmds_quant;
	
	if (has_pipes(mini->token_list))
	{
		cmds_quant = count_commands(token_list);
    cmds = split_commands_by_pipe(token_list, cmds_quant);
    ft_execute_pipeline(cmds, cmds_quant, envp);
    free(cmds);
    
	}
	else
	{
		if (ft_is_builtin(mini->token_list->value))
			mini->exit_status = ft_execute_bultin(mini);
		else
			ft_execute_simple_command(mini->token_list, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*cmd_line;

	(void)argc;
	(void)argv;
	mini.env_list = init_env(envp);
	mini.exit_status = 0;
	while (1)
	{
		cmd_line = readline("minishell> ");
		if (!cmd_line || ft_str_equal(cmd_line, "exit"))
		{
			if (cmd_line)
				free(cmd_line);
			break ;
		}
		if (cmd_line)
		{
			mini.token_list = NULL;
			init_token_list(&mini.token_list, cmd_line);
			ft_execute_commad(&mini, envp);
			free_token_list(mini.token_list);
		}
		free(cmd_line);
	}
	return (mini.exit_status);
}
