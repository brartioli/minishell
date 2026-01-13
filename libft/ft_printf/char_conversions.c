/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:18 by malcosta          #+#    #+#             */
/*   Updated: 2025/08/03 12:49:00 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
	return (len);
}

int	ft_putchar(int c)
{
	int	len;

	len = 0;
	len = write(1, &c, 1);
	return (len);
}
