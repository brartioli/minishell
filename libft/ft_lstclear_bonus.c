/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maluojuara <maluojuara@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:25:23 by malcosta          #+#    #+#             */
/*   Updated: 2025/07/30 12:03:34 by maluojuara       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and all its
successors, using the function ’del’ and free(3).
Finally, set the pointer to the list to NULL.
 * 
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete
the content of the node.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
