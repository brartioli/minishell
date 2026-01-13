/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:12:53 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 18:01:14 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns a pointer to a new string which is a
       duplicate of the string s.  Memory for the new 
	   string is obtained with malloc(3), and can be 
	   freed with free(3).
 * 
 * @param s The string to be duplicated.
 * @return char* A pointer to the duplicated string. It 
 		returns NULL if insufficient memory was
		available, with errno set to indicate the error.
 */

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	len;

	len = ft_strlen(s);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return (NULL);
	ft_memcpy(out, s, len);
	out[len] = '\0';
	return (out);
}
