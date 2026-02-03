/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/03 18:26:30 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



// static int	find_cmd(char *cmd, char *path)
// {
// 	char	**split_paths;
// 	int		i;
// 	char	*temp;
// 	char	*cmd_all;

// 	i = 0;
// 	split_paths = ft_split(path, ':');
// 	while (split_paths[i])
// 	{
// 		temp = ft_strjoin(split_paths[i], "/");
// 		cmd_all = ft_strjoin(temp, cmd);
// 		free(temp);
// 		if (access(cmd_all, F_OK) == 0 && access(cmd_all, X_OK) == 0)
// 		{
// 			free(cmd_all);
// 			ft_free_split(split_paths);
// 			return (1);
// 		}
// 		free(cmd_all);
// 		i++;
// 	}
// 	ft_free_split(split_paths);
// 	return (0);
// }

// no_que_eu_quero = get_node(lista_completa, "PATH");

// static char *ft_get_env_node(t_env *env_list, char *name)
// {
// 	while (env_list)
// 	{
// 		if (ft_str_equal(env_list->name, name))
// 			return (env_list->value);
// 		env_list = env_list->next;
// 	}
// 	return (NULL);
// }

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

int	main (int argc, char **argv, char **envp)
{
	t_env	*env_list;
	t_token *token_list;
	char	*cmd_line;
	
	(void)argc;
	(void)argv;
	token_list = NULL;
	env_list = NULL;
	env_list = init_env(envp);
	while (1)
	{
		cmd_line = readline("minishell> ");
		if (ft_str_equal(cmd_line, "exit") == 1)
			break ;
		else
		{
			init_token_list(&token_list, cmd_line);
			ft_printf("%s\n", token_list->value);
			if (ft_is_builtin(token_list->value))
			{
				ft_execute_bultin(*token_list, **env_list);
			}
			else
			{
				ft_printf("executar path\n");
			// ft_executar_bultin(cmd, args);
			//olhar pro primeiro elemento do token list e decidir se eh um bultin ou se eh do path
			// se for do path: executar a funcao path
			// se for bultin: executar a funcao bultin
			}
		}
		free_token_list(token_list);
		free(cmd_line);
	}
	return (0);
}
