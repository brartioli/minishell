/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:12:45 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 17:47:19 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns an
array of strings obtained by splitting ’s’ using
the character ’c’ as a delimiter. The array must
end with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char** The array of new strings resulting from the split.
NULL if the allocation fails.
 */

static int	count_sub(char const *str, char c)
{
	int	sub;
	int	i;

	sub = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 && str[i] != c) || (str[i] != c && str[i - 1] == c))
			sub++;
		i++;
	}
	return (sub);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	free_split(char **split, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;
	int		j;

	out = malloc((count_sub(s, c) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_sub(s, c))
	{
		while (s[i] == c)
			i++;
		out[j] = ft_substr(s, i, word_len(s, c, i));
		if (!out[j])
		{
			free_split(out, j);
			return (NULL);
		}
		i += word_len(s, c, i);
		j++;
	}
	out[j] = NULL;
	return (out);
}
