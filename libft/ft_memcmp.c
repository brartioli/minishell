/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:11:54 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 12:22:54 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first n bytes (each interpreted
       as unsigned char) of the memory areas s1 and s2.
 * 
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n  Number of bytes to compare.
 * @return int Returns an integer less than, equal to, or
       greater than zero if the first n bytes of s1 is found,
       respectively, to be less than, to match, or be greater than the
       first n bytes of s2.

       For a nonzero return value, the sign is determined by the sign of
       the difference between the first pair of bytes (interpreted as
       unsigned char) that differ in s1 and s2.

       If n is zero, the return value is zero.
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				i;

	i = 0;
	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	return (0);
}
