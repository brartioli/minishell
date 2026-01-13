/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:46:53 by malcosta          #+#    #+#             */
/*   Updated: 2025/08/03 12:12:57 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	normal_print(char **str)
{
	int	printed;

	printed = 0;
	while (**str && **str != '%')
	{
		printed += ft_putchar(**str);
		(*str)++;
	}
	if (**str)
		(*str)++;
	return (printed);
}

int	format_prints(va_list *args, char format)
{
	int	printed;

	printed = 0;
	if (format == 'c')
		printed = ft_putchar(va_arg(*args, int));
	else if (format == 's')
		printed = ft_putstr(va_arg(*args, const char *));
	else if (format == 'd' || format == 'i')
		printed = ft_putnbr(va_arg(*args, int));
	else if (format == 'u')
		printed = ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed = ft_putnbr_hexa(va_arg(*args, int), format);
	else if (format == 'p')
		printed = ft_print_ptr(va_arg(*args, void *));
	else if (format == '%')
		printed = ft_putchar('%');
	return (printed);
}
