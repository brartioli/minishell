/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:08:08 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:38:37 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts a lower-case letter to the corresponding
     upper-case letter.  The argument must be representable 
	 as an unsigned char or the value of EOF.
 * 
 * @param c The char to convert (as int).
 * @return int The converted char (as int).
 */

int	ft_toupper(int c)
{
	int	out;

	out = c;
	if (c >= 97 && c <= 122)
		out = c - 32;
	return (out);
}
