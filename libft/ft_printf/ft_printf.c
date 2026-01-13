/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:09:25 by malcosta          #+#    #+#             */
/*   Updated: 2025/08/03 12:37:37 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fixed, ...)
{
	int		nb_printed;
	va_list	args;
	char	*ptr;

	va_start(args, fixed);
	nb_printed = 0;
	ptr = (char *)fixed;
	while (*ptr)
	{
		nb_printed += normal_print(&ptr);
		if (!*ptr)
			break ;
		nb_printed += format_prints(&args, *ptr);
		ptr++;
	}
	va_end(args);
	return (nb_printed);
}

// #include <stdio.h>
// int	main (void)
// {
// 	char	*c = "abcd";
// 	char	a = '9';
// 	// int n = 42;
//     // int *ptr = &n;
//     void *null_ptr = NULL;

// 	printf("%d\n", ft_printf("hey %% %s   %c %d %i   | ", c, a, 90, 100));
// 	printf("%d\n", printf("hey %% %s   %c %d %i   | ", c, a, 90, 100));
// 	printf("\n%p\n", null_ptr);
// 	ft_printf("\n%p\n", null_ptr);
// 	printf("%d\n", ft_printf("%x %X ", -1, -1));
// 	printf("%d\n", printf("%x %X ", -1, -1));
// 	return (0);
// }