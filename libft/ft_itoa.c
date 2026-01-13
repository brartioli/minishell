/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:18:59 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/29 19:07:07 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an integer to a null-terminated string.
 * 
 * @param n The integer to convert.
 * @return char* Pointer to the newly allocated string representing 
 * the integer.
 */

static int	count_len(long nb)
{
	int		len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	if (nb < 10)
		return (len);
	len++;
	while (nb / 10 >= 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static int	my_pow(int nb, int pow)
{
	int	res;

	res = nb;
	while (pow > 1)
	{
		res = res * nb;
		pow--;
	}
	return (res);
}

static void	last_digit(int nb, int i, char *out)
{
	out[i] = nb + 48;
	i++;
	out[i] = '\0';
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*out;
	int		i;
	int		digits;

	nb = n;
	i = 0;
	digits = count_len(nb);
	out = ft_calloc(digits + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (nb < 0)
	{
		out[i++] = '-';
		nb *= -1;
		digits--;
	}
	while (digits > 1)
	{
		out[i++] = nb / (my_pow(10, digits - 1)) + 48;
		nb = nb % (my_pow(10, digits - 1));
		digits--;
	}
	last_digit(nb, i, out);
	return (out);
}
