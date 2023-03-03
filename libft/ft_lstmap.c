/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:40:42 by lspohle           #+#    #+#             */
/*   Updated: 2022/12/29 19:08:14 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Note
//  Prototyped as
//  t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//  -> lst: the address of a pointer to a node
//  -> f: the address of the function used to iterate on the list
//  -> del : the address of the function used to delete the content of a node
//     if needed
//  -> iterates the list 'lst' and applies the function 'f' on the content of
//     each node
//  -> creates a new list resulting of the successive applications of
//     the function ’f’
//  -> the ’del’ function is used to delete the content of a node if needed
//  -> the memory of ’next’ must not be freed
//  -> external functs: malloc, free
//  -> return: the new list
//             NULL if allocation fails

#include "libft.h"

// Iterates 'lst' and applies 'f' on the content of each node
// Creates new list resulting of successive applications of ’f’
// ’del’ is used to delete the content of a node if needed
// Returns the new list
// Returns NULL if allocation failed
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*replacement;

	head = NULL;
	while (lst != NULL)
	{
		new = (t_list *) malloc (sizeof(t_list));
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			free(head);
			return (NULL);
		}
		replacement = f(lst->content);
		new->content = replacement;
		ft_lstadd_back(&head, new);
		lst = lst->next;
		new->next = NULL;
	}
	return (head);
}
