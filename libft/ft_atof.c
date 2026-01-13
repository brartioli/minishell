/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:21:30 by malcosta          #+#    #+#             */
/*   Updated: 2026/01/08 20:22:05 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		result += (str[i++] - '0') * fraction;
		fraction *= 0.1;
	}
	return (result * sign);
}
