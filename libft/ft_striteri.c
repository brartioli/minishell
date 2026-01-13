/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:34:14 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:01:56 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief pplies the function ’f’ to each character of the
string passed as argument, passing its index as
the first argument. Each character is passed by
address to ’f’ so it can be modified if necessary.
 * 
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
