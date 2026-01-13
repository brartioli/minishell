/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:12:03 by maluojuara        #+#    #+#             */
/*   Updated: 2025/07/29 19:03:21 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes 
 * each and initializes all bytes to zero.
 * 
 * @param nmemb Number of elements.
 * @param size Size in bytes of each element.
 * @return Pointer to the allocated memory, or NULL if 
 * allocation fails or overflow occurs.
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;
	size_t	alloc;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	alloc = nmemb * size;
	out = malloc(alloc);
	if (!out)
		return (NULL);
	ft_bzero(out, alloc);
	return (out);
}
