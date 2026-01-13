/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:13:29 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:31:10 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Search for the last occurrence of the character c in the string s.
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

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;
	size_t			len;

	len = ft_strlen(s);
	ptr = s + len;
	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)ptr);
	while (len > 0)
	{
		ptr--;
		len--;
		if (*ptr == uc)
			return ((char *)ptr);
	}
	return (NULL);
}
