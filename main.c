/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/17 13:51:28 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main (int argc, char **argv, char **envp)
{
	// t_env	*env;
	// t_token *token;
	char	*cmd_line;
	
	(void)argc;
	(void)argv;
	(void)envp;
	// env = init_env(envp);
	// if (!env)
	// 	ft_printf("Error");
	
	while (1)
	{
		cmd_line = readline("minishell> ");
		if (ft_str_equal(cmd_line, "exit") == 1)
			break ;
		else
		{
			// CRIAR UMA FUNÇÃO INIT_TOKEN OU TOKENIZE QUE VAI TER OS SEGUINTES PASSOS:
			// splitar a linha de comando
			// pegar o resultado do split e percorrer
			// armazenar na lisra de tookens
			ft_printf("tokenizar\n");
		}
	}
	return (0);
}