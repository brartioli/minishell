/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:46:12 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 17:42:55 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief fills the first n bytes of the memory area
       pointed to by s with the constant byte c.
 * 
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to be set. It is passed as an int, 
 	but the function fills the memory with the unsigned char 
	conversion of this value (to fill byte by byte).
 * @param n Number of bytes to be set to the value c.
 * @return void* Pointer to the memory area s.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
