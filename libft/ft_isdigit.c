/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:02:43 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 11:59:24 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for a decimal digit character (0 - 9).
 * 
 * @param c -> integer value representing the char to be tested
 * @return zero if the character tests
 *   false and return non-zero if the character tests true.
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
