/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:00:58 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 11:45:18 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for an ASCII character, which is any
     character between 0 and octal 0177 (127 decimal) inclusive.
 * 
 * @param c -> integer value representing the char to be tested
 * @return zero if the integer tests false and
     returns non-zero if the integer tests true.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
