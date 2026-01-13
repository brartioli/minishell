/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:11:45 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/29 19:21:19 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s
 *        for the first instance of c. Both c and the bytes of the memory
 *        area pointed to by s are interpreted as unsigned char.
 * 
 * @param s Pointer to the memory area to be scanned.
 * @param c Character to search for (converted to unsigned char).
 * @param n Number of bytes to scan.
 * @return void* Pointer to the first occurrence of c in s, or NULL if 
 * not found.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			uc;
	size_t					i;
	const unsigned char		*str;

	uc = (unsigned char)c;
	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
