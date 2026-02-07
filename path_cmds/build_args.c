/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:14:51 by bfernan2          #+#    #+#             */
/*   Updated: 2026/02/07 11:28:10 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_args(t_token *start)
{
	t_token	*current;
	int		count;

	count = 0;
	current = start;
	while (current && !ft_str_equal(current->type, TYPE_PIPE))
	{
		if (ft_str_equal(current->type, TYPE_WORD))
			count++;
		current = current->next;
	}
	return (count);
}

char	**allocate_args(int count)
{
	char	**args;

	args = malloc(sizeof(char *) * (count + 1));
	return (args);
}

int	fill_args(char **args, t_token *start)
{
	t_token	*current;
	int		i;

	i = 0;
	current = start;
	while (current && !ft_str_equal(current->type, TYPE_PIPE))
	{
		if (ft_str_equal(current->type, TYPE_WORD))
		{
			args[i] = ft_strdup(current->value);
			if (!args[i])
			{
				while (i > 0)
					free(args[--i]);
				return (-1);
			}
			i++;
		}
		current = current->next;
	}
	args[i] = NULL;
	return (0);
}

char	**build_args(t_token *start)
{
	char	**args;
	int		count;

	count = count_args(start);
	if (count == 0)
		return (NULL);
	args = allocate_args(count);
	if (!args)
		return (NULL);
	if (fill_args(args, start) == -1)
	{
		free(args);
		return (NULL);
	}
	return (args);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
