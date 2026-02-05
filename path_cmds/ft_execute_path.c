/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:04:41 by malcosta          #+#    #+#             */
/*   Updated: 2026/02/03 20:52:09 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"

void	ft_execute_path(t_token *token_list, t_env *env_list)
{
	char	*full_path;
	pid_t	pid;
	char	*argv[2];
	argv[0] = token_list->value;
	argv[1] = NULL;

	if (!token_list || !token_list->value)
		return ;
	full_path = get_full_path(token_list->value, env_list);
	if (!full_path)
	{
		ft_printf("%s: command not found\n", token_list->value);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(full_path);
		return ;
	}
	else if (pid == 0)
	{
		execve(full_path, argv, env_list_to_array(env_list));
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, NULL, 0);
	free(full_path);
}

char	*get_full_path(char *cmd, t_env *env_list)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	char	*tmp;
	int		i;

	if (!cmd)
		return (NULL);
	path = get_path_from_env(env_list);
	if (!path)
		return (NULL);
	split_path = ft_split(path, ':');
	if (!split_path)
		return (NULL);
	full_path = NULL;
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			ft_free_split(split_path);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		i++;
	}
	ft_free_split(split_path);
	return (NULL);
}



char *get_path_from_env(t_env *env_list)
{
	while (env_list != NULL)
	{
		if (ft_str_equal(env_list->name, "PATH") == 1)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}*/


// char	**build_args(t_token *token)
// {
// 	t_token	*tmp;
// 	char	**args;
// 	int		count_args;

// 	if (!token)
// 		return (NULL);


// 	count_args = 0;
// 	tmp = token;
// 	while (tmp && !ft_str_equal(tmp->type, TYPE_PIPE))
// 	{
// 		if (ft_str_equal(tmp->type, TYPE_WORD))
// 			count_args++;
// 		tmp = tmp->next;
// 	}
// 	args = malloc (sizeof(char *) * (count_args + 1));
// 	if (!args)
// 		return (NULL);
// 	i = 0;
// 	tmp = 
// }


//     // 4️⃣ Loop para achar o executável
//     full_path = NULL;
//     i = 0;
//     while (dirs[i])
//     {
//         // monta full_path = dir + "/" + cmd
//         full_path = ft_strjoin(dirs[i], "/");
//         full_path = ft_strjoin(full_path, cmd);

//         // testa se existe e é executável
//         if (access(full_path, X_OK) == 0)
//             break; // achou
//         free(full_path);
//         full_path = NULL;
//         i++;
//     }

//     if (!full_path)
//     {
//         ft_printf("command not found: %s\n", cmd);
//         // aqui seria bom liberar dirs
//         return;
//     }

//     // 5️⃣ Preparar argv (aqui simplificado: só o comando por enquanto)
//     char *argv[2];
//     argv[0] = cmd;
//     argv[1] = NULL;

//     // 6️⃣ Fork + execve
//     if (fork() == 0)
//     {
//         execve(full_path, argv, NULL); // envp você pode passar se quiser
//         perror("execve");
//         exit(EXIT_FAILURE);
//     }
//     else
//     {
//         wait(NULL); // espera o filho terminar
//     }

//     free(full_path);
//     // aqui seria bom liberar dirs também
// }


	// char	*path_env;
	// char	*path;
	// char	**cmds;

	// cmds = ft_split(cmd, ' ');
	// if (!cmds || !cmds[0] || cmds[0][0] == '\0')
	// {
	// 	if (cmds)
	// 		ft_free_split(cmds);
	// 	ft_putstr_fd("pipex: command not found: \n", 2);
	// 	exit (127);
	// }
	// path_env = get_path(env);
	// path = find_cmd(cmds[0], path_env);
	// if (!path)
	// {
	// 	ft_putstr_fd("pipex: command not found: ", 2);
	// 	ft_putendl_fd(cmds[0], 2);
	// 	cleanup_and_exit(cmds, NULL, path_env, 127);
	// }
	// if (execve(path, cmds, env) == -1)
	// 	cleanup_and_exit(cmds, path, path_env, 1);
//}