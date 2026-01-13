/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:32 by malcosta          #+#    #+#             */
/*   Updated: 2025/08/03 12:29:48 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *toprint, ...);

// CHAR CONVERSIONS
int	ft_putstr(const char *str);
int	ft_putchar(int c);

// NUMBER CONVERSIONS
int	ft_putnbr(int nbr);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putnbr_hexa(unsigned int nbr, char x);
int	ft_putnbr_hexa_long(unsigned long nbr, char x);
int	ft_print_ptr(void *ptr);

// UTILS
int	normal_print(char **str);
int	format_prints(va_list *args, char format);

#endif