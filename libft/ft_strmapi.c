/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:35:24 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:18:40 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.
 * 
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 * @return char* 
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*out;
	unsigned int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	out = ft_strdup(s);
	if (!out)
		return (NULL);
	while (out[i])
	{
		out[i] = f(i, out[i]);
		i++;
	}
	return (out);
}
