/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 01:20:29 by maluojuara        #+#    #+#             */
/*   Updated: 2025/09/19 01:20:30 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	const char	*ptr;
	int			sign;
	long		out;

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
