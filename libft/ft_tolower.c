/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:13:41 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:38:22 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an upper-case letter to the corresponding
     lower-case letter.  The argument must be representable 
	 as an unsigned char or the value of EOF.
 * 
 * @param c The char to convert (as int).
 * @return int The converted char (as int).
 */

int	ft_tolower(int c)
{
	int	out;

	out = c;
	if (c >= 65 && c <= 90)
		out = c + 32;
	return (out);
}
