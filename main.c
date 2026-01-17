/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/17 11:55:02 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main (int argc, char **argv, char **envp)
{
	t_env	*env;
	t_token *token;
	char	*cmd_line;
	
	(void)argc;
	(void)argv;
	env = init_env(envp);
	if (!env)
		ft_printf("Error");
	
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
			ft_printf("tokenizar");
		}
	}
	return (0);
}