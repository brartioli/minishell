/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:38 by malcosta          #+#    #+#             */
/*   Updated: 2025/08/03 12:32:26 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	nb;
	int		len;

	nb = nbr;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + 48);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	int				len;

	len = 0;
	if (nbr > 9)
		len += ft_putnbr_unsigned(nbr / 10);
	len += ft_putchar(nbr % 10 + 48);
	return (len);
}

int	ft_putnbr_hexa(unsigned int nbr, char x)
{
	char	*base;
	int		len;

	len = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else if (x == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	if (nbr > 15)
		len += ft_putnbr_hexa(nbr / 16, x);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}

int	ft_putnbr_hexa_long(unsigned long nbr, char x)
{
	char	*base;
	int		len;

	len = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else if (x == 'X')
		base = "0123456789ABCDEF";
	else
		return (0);
	if (nbr > 15)
		len += ft_putnbr_hexa_long(nbr / 16, x);
	len += ft_putchar(base[nbr % 16]);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	len = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		len = ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_putnbr_hexa_long(addr, 'x');
	return (len);
}
