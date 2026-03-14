/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:18:52 by bfernan2          #+#    #+#             */
/*   Updated: 2026/03/14 12:43:40 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <sys/wait.h>

// Define token types
# define TYPE_WORD "WORD"
# define TYPE_PIPE "PIPE"
# define TYPE_REDIR_IN "REDIR_IN"
# define TYPE_REDIR_OUT "REDIR_OUT"
# define TYPE_REDIR_APPEND "APPEND"
# define TYPE_HEREDOC "HEREDOC"

// Structs
typedef struct s_token
{
	char			*value;
	char			*type;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_mini
{
	t_env	*env_list;
	t_token	*token_list;
	int		exit_status;
}	t_mini;

typedef struct s_cmd
{
	char	**args;
	char	*infile;
	char	*outfile;
	int		append;
	int		heredoc_fd;
}	t_cmd;

// FUNCTIONS

//Main
void	ft_execute_command(t_mini *mini, t_cmd *cmd);
int		ft_is_builtin(char *cmd);

// Tokenize
void	init_token_list(t_token **token_list, char *cmd_line);
t_token	*create_token(char *value, char *type);
void	add_token_back(t_token **token_list, t_token *new_token);
void	print_token_list(t_token *token_list);
void	free_token_list(t_token *token_list);
char	**split_cmd(char *str);

// Parsing
t_cmd	**parse_input(t_token *token_list, t_env *env_list, int exit_status);
t_cmd	*parse_command(t_token *token_list, t_env *env_list, int exit_status);
void	process_quotes(t_token *token_list);
t_cmd	*init_command(void);
void	free_cmd(t_cmd *cmd);
int		has_redirect(t_cmd *cmd);

//Expand variables
int		get_var_name_len(char *var_name);
char	*extract_var_name(char *start);
char	*build_expanded_str(char *str, char *dol_pos, char *value, int var_len);
char	*expand_token(char *str, t_env *env_list, int exit_status);
char	*get_env_value(t_env *env_list, char *var_name);
void	expand_variables(t_token *token_list, t_env *env_list, int exit_status);

// Extracting
char	*extract_infile(t_token *token_list);
char	*extract_outfile(t_token *token_list);
int		has_append_flag(t_token *token_list);

//Env
t_env	*init_env(char **envp);
void	add_env_back(t_env **env_list, t_env *new_env);
t_env	*create_env_node(char *name, char *value);
char	**env_list_to_array(t_env *env_list);
void	free_array(char **array);
void	free_env_list(t_env *env_list);

//Builtin
int		ft_execute_builtin(t_mini *mini, t_cmd *cmd);
int		ft_execute_pwd(void);
int		ft_execute_env(t_mini *mini, t_cmd *cmd);
int		ft_execute_exit(t_mini	*mini);
int		ft_execute_echo(t_cmd *cmd);
int		ft_execute_unset(t_mini *mini, t_cmd *cmd);
int		ft_execute_export(t_mini *mini, t_cmd *cmd);
int		ft_execute_export(t_mini *mini, t_cmd *cmd);
void	print_export(t_env *env_list);
void	process_export_arg(t_mini *mini, char *arg);
void	split_var_value(char *arg, char **name, char **value);
int		is_valid_identifier(char *name);
void	add_or_update_env(t_mini *mini, char *name, char *value);
int		ft_execute_cd(t_mini *mini, t_cmd *cmd);
void	update_pwd(t_mini *mini);
char	*get_cd_path(t_mini *mini, t_cmd *cmd);

//Utils Builtin
int		is_valid_number(char *str);

//Path execution
void	ft_exec(t_cmd *cmd, char **envp);
void	ft_execute_simple_command(t_cmd *cmd, t_mini *mini);
char	*get_path_from_env(char **env);
char	*get_full_path(char *cmd, char **envp);
void	apply_redirects(t_cmd *cmd);

//Args handling
int		count_args(t_token *start);
char	**allocate_args(int count);
int		fill_args(char **args, t_token *start);
char	**build_args(t_token *start);
void	free_args(char **args);

//Pipeline execution
void	ft_execute_pipeline(t_cmd **cmds, int cmds_quant, t_mini *mini);
void	close_all_pipes(int **pipes, int cmds_quant);
void	wait_all_children(pid_t *pids, int cmds_quant);
void	free_pipes(int **pipes, int cmds_quant);

//Pipeline parsing utils
int		count_commands(t_token *token_list);
t_token	**split_commands_by_pipe(t_token *token_list, int cmds_quant);
int		**create_pipes(int cmds_quant);
int		has_pipes(t_token *token_list);
void	free_pipes(int **pipes, int cmds_quant);

//Signals
void	setup_signals(void);
void	handle_sigquit(int sig);
void	handle_sigint(int sig);

//Heredoc
int		handle_heredoc(char *delimiter);
int		extract_heredoc(t_token *token_list);

#endif