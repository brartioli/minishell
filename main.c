/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/12 19:21:20 by bfernan2         ###   ########.fr       */
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
	if (ft_str_equal(cmd, "export"))
		return (1);
	if (ft_str_equal(cmd, "cd"))
		return (1);
	return (0);
}

void	ft_execute_command(t_mini *mini, t_cmd *cmd)
{
	t_cmd	**cmds;
	int		cmd_count;

	if (has_pipes(mini->token_list))
	{
		cmds = parse_input(mini->token_list, mini->env_list, mini->exit_status);
		cmd_count = count_commands(mini->token_list);
		ft_execute_pipeline(cmds, cmd_count, mini);
		return ;
	}
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (ft_is_builtin(cmd->args[0]))
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

static void	run_minishell(t_mini *mini)
{
	char	*cmd_line;
	t_cmd	*cmd;

	while (1)
	{
		cmd_line = readline("minishell> ");
		if (!cmd_line)
		{
			ft_putstr_fd("Exit\n", 1);
			break ;
		}
		if (*cmd_line)
			add_history(cmd_line);
		mini->token_list = NULL;
		init_token_list(&mini->token_list, cmd_line);
		cmd = parse_command(mini->token_list, mini->env_list,
				mini->exit_status);
		ft_execute_command(mini, cmd);
		free_cmd(cmd);
		free_token_list(mini->token_list);
		free(cmd_line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	handle_args(argc, argv);
	setup_signals();
	mini.env_list = init_env(envp);
	mini.exit_status = 0;
	run_minishell(&mini);
	return (mini.exit_status);
}
