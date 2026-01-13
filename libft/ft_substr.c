/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:06:51 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:33:21 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc(3)) and returns a
	substring from the string ’s’.
	The substring starts at index ’start’ and has a
	maximum length of ’len’.
 * 
 * @param s The original string from which to create the
	substring.
 * @param start The starting index of the substring within ’s’.
 * @param len The maximum length of the substring.
 * @return char* The substring.
	NULL if the allocation fails.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		out = malloc(sizeof(char));
		if (!out)
			return (NULL);
		*out = '\0';
		return (out);
	}
	if (len >= s_len - start)
		len = s_len - start;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s + start, len + 1);
	return (out);
}
