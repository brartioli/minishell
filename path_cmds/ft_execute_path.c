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

#include "../minishell.h"

char    *get_full_path(char *cmd, char **env)
{
    char    *path;
    char    **split_path;
    char    *full_path;
    char    *tmp;
    int     i;

    if (!cmd)
        return (NULL);
    
    // Se tem '/', testa o caminho direto
    if (ft_strchr(cmd, '/'))
    {
        if (access(cmd, X_OK) == 0)
            return (ft_strdup(cmd));
        return (NULL);
    }
    
    // Busca no PATH
    path = get_path_from_env(env);  // ← Mudou aqui!
    if (!path)
        return (NULL);
    
    split_path = ft_split(path, ':');
    if (!split_path)
        return (NULL);
    
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
        i++;
    }
    
    ft_free_split(split_path);
    return (NULL);
}

char *get_path_from_env(char **env)
{
    int i;
    
    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
            return (env[i] + 5);
        i++;
    }
    return (NULL);
}


void    ft_execute_path(t_token *token_list, char **envp)
{
    char    *full_path;
    char    **args;
    pid_t   pid;

    if (!token_list || !token_list->value)
        return ;
    
    args = build_args(token_list);
    if (!args)
        return ;
    
    full_path = get_full_path(args[0], envp);  // ← Passou envp
    if (!full_path)
    {
        ft_printf("%s: command not found\n", args[0]);
        free_args(args);
        return ;
    }
    
    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        free(full_path);
        free_args(args);
        return ;
    }
    else if (pid == 0)
    {
        execve(full_path, args, envp);  // ← Passou envp
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
        waitpid(pid, NULL, 0);
    
    free(full_path);
    free_args(args);
}
