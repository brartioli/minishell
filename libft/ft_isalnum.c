/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:26:02 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 11:45:21 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tests for any character for which isalpha(3) or
     isdigit(3) is true.  The value of the argument must be 
	 representable as an unsigned char or the value of EOF.
 * 
 * @param c -> integer value representing the char to be tested
 * @return zero if the character tests false and
     returns non-zero if the character tests true.
 */

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
