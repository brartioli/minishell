/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:04:32 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/06 18:44:05 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int count_word(char *str)
{
	int		count;
	int		in_word;
	int		in_quotes;
	char	quote_char;

	count = 0;
	in_word = 0;
	in_quotes = 0;
	while (*str)
	{
		if ((*str == '"' || *str == '\'') && !in_quotes)
		{
			in_quotes = 1;
			quote_char = *str;
			in_word = 1;
		}
		else if (*str == quote_char && in_quotes)
			in_quotes = 0;
		else if (*str == ' ' && !in_quotes)
		{
			if (in_word)
				count++;
			in_word = 0;
		}
		else
			in_word = 1;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

static char *extract_word(char *str, int *i)
{
	int		start;
	int		in_quotes;
	char	quote_char;

	start = *i;
	in_quotes = 0;
	
	// Se começa com operador (fora de aspas), extrai ele
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
	{
		if (str[*i] == '<' && str[*i + 1] == '<')
			*i += 2;
		else if (str[*i] == '>' && str[*i + 1] == '>')
			*i += 2;
		else
			(*i)++;
		return (ft_substr(str, start, *i - start));
	}
	
	// Extrai palavra normal ou entre aspas
	while (str[*i])
	{
		if ((str[*i] == '"' || str[*i] == '\'') && !in_quotes)
		{
			in_quotes = 1;
			quote_char = str[*i];
		}
		else if (str[*i] == quote_char && in_quotes)
			in_quotes = 0;
		else if (!in_quotes && (str[*i] == ' ' || str[*i] == '<' || 
				str[*i] == '>' || str[*i] == '|'))
			break;
		(*i)++;
	}
	return (ft_substr(str, start, *i - start));
}

char **split_cmd(char *str)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	words = count_word(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			result[j++] = extract_word(str, &i);
	}
	result[j] = NULL;
	return (result);
}
