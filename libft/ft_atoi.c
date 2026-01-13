/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:06:20 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/29 19:00:24 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the initial portion of the string to int.
 * @param nptr --> Pointer to the beginning of the string.
 * @return The converted value or 0 if it is an error.
*/

int	ft_atoi(const char *nptr)
{
	const char	*ptr;
	int			sign;
	int			out;

	ptr = nptr;
	sign = 1;
	out = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		out *= 10;
		out += *ptr - 48;
		ptr++;
	}
	return (out * sign);
}
