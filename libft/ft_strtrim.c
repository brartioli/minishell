/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:13:33 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:32:08 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.
 * 
 * @param s1 The string to be trimmed.
 * @param set The string containing the set of characters
to be removed.
 * @return char* The trimmed string.
NULL if the allocation fails.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	while (s1[i])
	{
		if (ft_strchr(set, s1[j]))
			j--;
		else
			break ;
	}
	return (ft_substr(s1, i, (j - i + 1)));
}
