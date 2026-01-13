/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:12:49 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:28:51 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a pointer to the first occurrence of
       the character c in the string s.
 * 
 * @param s The string to search (pointer).
 * @param c The char to be found (as int) and then
		converted to unsigned char (byte by byte).
 * @return char* A pointer to the matched character or
 		NULL if the character is not found. The
       terminating null byte is considered part of 
	   the string, so that if c is specified as '\0', 
	   these functions return a pointer to the
       terminator.
 */

char	*ft_strchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;

	ptr = s;
	uc = (unsigned char)c;
	if (uc == '\0')
	{
		while (*ptr)
			ptr++;
		return ((char *)ptr);
	}
	while (*ptr)
	{
		if (*ptr == uc)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
