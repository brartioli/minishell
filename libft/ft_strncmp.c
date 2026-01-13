/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:18:30 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:20:19 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare not more than n bytes (bytes
       that follow a NUL character are not compared) from the array
       pointed to by s1 to the array pointed to by s2. Compares byte 
	   by byte.
 * 
 * @param s1 String pointed by s1.
 * @param s2 String pointed by s2.
 * @param n Number of bytes to compare.
 * @return int Upon successful completion, strncmp() shall return an integer
       greater than, equal to, or less than 0, if the possibly null-
       terminated array pointed to by s1 is greater than, equal to, or
       less than the possibly null-terminated array pointed to by s2
       respectively.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n > 0 && (*ptr1 || *ptr2))
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
