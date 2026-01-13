/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malcosta <malcosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:33:14 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/29 19:01:52 by malcosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erases  the  data  in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes  
	   containing '\0') to that area.
 * @param s --> Pointer to the memory area to be zeroed.
 * @param n --> Number of bytes to set to zero.
 */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
