/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/19 17:55:27 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute_command(t_mini *mini, t_cmd *cmd)
{
	t_cmd	**cmds;
	int		cmd_count;

	if (has_pipes(mini->token_list))
	{
		cmds = parse_input(mini->token_list, mini->env_list, mini->exit_status);
		cmd_count = count_commands(mini->token_list);
		ft_execute_pipeline(cmds, cmd_count, mini);
	}
	else if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	else if (ft_is_builtin(cmd->args[0]))
	{
		if (has_redirect(cmd))
			ft_execute_simple_command(cmd, mini);
		else
			mini->exit_status = ft_execute_builtin(mini, cmd);
	}
	else
		ft_execute_simple_command(cmd, mini);
}

static void	handle_args(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Usage: ./minishell (with no other arguments) \n", 2);
		exit (1);
	}
}

static void	process_command_line(t_mini *mini, char *cmd_line)
{
	t_cmd	*cmd;

	mini->token_list = NULL;
	init_token_list(&mini->token_list, cmd_line);
	cmd = NULL;
	if (!has_pipes(mini->token_list))
		cmd = parse_command(mini->token_list, mini->env_list,
				mini->exit_status);
	mini->current_cmd = cmd;
	ft_execute_command(mini, cmd);
	if (cmd)
		free_cmd(cmd);
	free_token_list(mini->token_list);
}

static void	run_minishell(t_mini *mini)
{
	char	*cmd_line;

	while (1)
	{
		cmd_line = readline("minishell> ");
		if (!cmd_line)
		{
			ft_putstr_fd("exit\n", 1);
			cleanup_all(mini);
			break ;
		}
		if (*cmd_line)
			add_history(cmd_line);
		process_command_line(mini, cmd_line);
		free(cmd_line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	ft_memset(&mini, 0, sizeof(t_mini));
	handle_args(argc, argv);
	setup_signals();
	mini.env_list = init_env(envp);
	mini.exit_status = 0;
	run_minishell(&mini);
	return (mini.exit_status);
}
