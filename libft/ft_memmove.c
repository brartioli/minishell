/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:12:03 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/29 19:09:03 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies len bytes from src to dest. The memory areas may overlap.
 * 
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param len Number of bytes to copy.
 * @return void* Pointer to the destination memory area.
 */

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (!ptr_dst && !ptr_src)
		return (0);
	if (ptr_dst <= ptr_src)
	{
		ft_memcpy(ptr_dst, ptr_src, len);
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			ptr_dst[i] = ptr_src[i];
		}
	}
	return (dest);
}
