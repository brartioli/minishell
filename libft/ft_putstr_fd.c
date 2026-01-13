/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:12:41 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 17:46:08 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the specified file
descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */

void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;

	ptr = s;
	if (!s)
		return ;
	while (*ptr)
	{
		ft_putchar_fd(*ptr, fd);
		ptr++;
	}
}
