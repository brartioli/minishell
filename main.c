/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/17 14:52:11 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main (int argc, char **argv, char **envp)
{
	// t_env	*env;
	t_token *token_list;
	char	*cmd_line;
	
	(void)argc;
	(void)argv;
	(void)envp;
	token_list = NULL;
	// env = init_env(envp);
	// CRIAR FUNCAO INIT_ENV
	// splitar o env
	// pegar o resultado do split e percorrer
	// armazenar na lista de envs
	// if (!env)
	// 	ft_printf("Error");
	
	while (1)
	{
		cmd_line = readline("minishell> ");
		if (ft_str_equal(cmd_line, "exit") == 1)
			break ;
		else
		{
			init_token_list(&token_list, cmd_line);
			//print_token_list(token_list);
		}
	}
	return (0);
}