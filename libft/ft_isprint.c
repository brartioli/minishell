/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:14:03 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 11:59:47 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any printing character, including space
     (‘ ’).  The value of the argument must be representable as an unsigned
     char or the value of EOF.
 * @param c -> integer value representing the char to be tested
 * @return zero if the character tests
 *   false and return non-zero if the character tests true.
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
