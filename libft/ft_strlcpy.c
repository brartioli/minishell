/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:13:16 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:16:56 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy strings. strlcpy() take the full size of the buffer 
 (not just the length) and guarantee to NUL-terminate the result 
 (as long as size is larger than 0). A byte for the NUL should 
 be included in size. Copies up to size - 1 characters from the 
 NUL-terminated string src to dst, NUL-terminating the result.
 * 
 * @param dst Destination buffer.
 * @param src Source string to be copied.
 * @param size Total size of dst buffer.
 * @return size_t Return the total length of the string they 
 tried to create. For strlcpy() that means the length of src.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
