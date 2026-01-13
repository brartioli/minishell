/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 21:11:22 by malcosta          #+#    #+#             */
/*   Updated: 2025/11/17 21:16:36 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_equal(char *str1, char *str2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (0);
		ptr1++;
		ptr2++;
	}
	return (*ptr1 == *ptr2);
}
