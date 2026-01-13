/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:13:24 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:39:37 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string little 
 	in the string big, where not more than len characters are searched.
	Characters that appear after a ‘\0’ character are not searched. 
 * 
 * @param big String to found.
 * @param little String to be found.
 * @param len Max characters to search.
 * @return char* If little is an empty string, big is returned; 
 	if little occurs nowhere in big, NULL is returned; otherwise 
	a pointer to the first character of the first occurrence of 
	little is returned.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(little + j) && (*(big + i + j) == *(little + j))
			&& (i + j) < len)
		{
			j++;
		}
		if (*(little + j) == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
