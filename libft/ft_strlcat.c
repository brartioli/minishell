/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:16:16 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:08:35 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Append src to dst, up to size bytes total, 
 * ensuring null-termination. If the destination 
 * buffer, limited by its size, isn't large enough to 
 * hold the copy, the resulting string is truncated 
 * (but it is guaranteed to be null-terminated).
 * They return the length of the total string they 
 * tried to create.
 * 
 * @param dst Destination buffer.
 * @param src Source string to append.
 * @param size Total size of dst buffer.
 * @return size_t Total length of the string it tried to create 
 * (initial dst + src).
 * If the return value is >= size, truncation happened.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	ptr_dst = dst;
	ptr_src = src;
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (i < size)
	{
		while (*ptr_dst)
			ptr_dst++;
		while (i < size - 1 && *ptr_src)
		{
			*ptr_dst = *ptr_src;
			ptr_dst++;
			ptr_src++;
			i++;
		}
		*ptr_dst = '\0';
		return (i + ft_strlen(ptr_src));
	}
	return (size + ft_strlen(src));
}
