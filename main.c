/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/01 18:13:05 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_builtin(char *cmd)
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

void	ft_execute_command(t_mini *mini, t_cmd *cmd, char **envp)
{
	t_cmd	**cmds;
	int		cmd_count;
	
	if (has_pipes(mini->token_list))
	{
		cmds = parse_input(mini->token_list, mini->env_list, mini->exit_status);
		cmd_count = count_commands(mini->token_list);
		ft_execute_pipeline(cmds, cmd_count, envp);
		// TO DO: free_cmds(cmds, cmd_count)
		return ;
		
	}
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (ft_is_builtin(cmd->args[0]))
	{
		if (has_redirect(cmd))
			ft_execute_simple_command(cmd, envp, mini);
		else
			mini->exit_status = ft_execute_builtin(mini, cmd);
	}
	else
		ft_execute_simple_command(cmd, envp, mini);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	char	*cmd_line;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	mini.env_list = init_env(envp);
	mini.exit_status = 0;
	while (1)
	{
		cmd_line = readline("minishell> ");
		if (!cmd_line)
			break ;
		if (*cmd_line)
			add_history(cmd_line);
		mini.token_list = NULL;
		init_token_list(&mini.token_list, cmd_line); // TOKENIZA		
		cmd = parse_command(mini.token_list, mini.env_list, mini.exit_status); // PARSEIA
		ft_execute_command(&mini, cmd, envp); // EXECUTA
		free_cmd(cmd); // IMPLEMENTAR - LIBERA CMD
		free_token_list(mini.token_list); // LIBERA TOKENS
		free(cmd_line);
	}
	return (mini.exit_status);
}
