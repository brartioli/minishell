/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:04:32 by malcosta          #+#    #+#             */
/*   Updated: 2026/03/14 16:13:57 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_quote(char c, int *in_quotes, char *quote_char, int *in_word)
{
	if ((c == '"' || c == '\'') && !*in_quotes)
	{
		*in_quotes = 1;
		*quote_char = c;
		*in_word = 1;
	}
	else if (c == *quote_char && *in_quotes)
		*in_quotes = 0;
}

static int	count_word(char *str)
{
	int		count;
	int		in_word;
	int		in_quotes;
	char	quote_char;

	count = 0;
	in_word = 0;
	in_quotes = 0;
	quote_char = 0;
	while (*str)
	{
		handle_quote(*str, &in_quotes, &quote_char, &in_word);
		if (*str == ' ' && !in_quotes && in_word && ++count)
			in_word = 0;
		else if (*str != ' ' || in_quotes)
			in_word = 1;
		str++;
	}
	if (in_word)
		count++;
	return (count);
}

static char	*extract_operator(char *str, int *i)
{
	int	start;

	start = *i;
	if (str[*i] == '<' && str[*i + 1] == '<')
		*i += 2;
	else if (str[*i] == '>' && str[*i + 1] == '>')
		*i += 2;
	else
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

static char	*extract_word(char *str, int *i)
{
	int		start;
	int		in_quotes;
	char	quote_char;

	start = *i;
	in_quotes = 0;
	quote_char = 0;
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		return (extract_operator(str, i));
	while (str[*i])
	{
		if ((str[*i] == '"' || str[*i] == '\'') && !in_quotes)
		{
			in_quotes = 1;
			quote_char = str[*i];
		}
		else if (str[*i] == quote_char && in_quotes)
			in_quotes = 0;
		else if (!in_quotes && (str[*i] == ' ' || str[*i] == '<'
				|| str[*i] == '>' || str[*i] == '|'))
			break ;
		(*i)++;
	}
	return (ft_substr(str, start, *i - start));
}

char	**split_cmd(char *str)
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
