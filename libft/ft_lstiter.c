/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspohle <lspohle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:29:19 by lspohle           #+#    #+#             */
/*   Updated: 2022/12/29 18:56:18 by lspohle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Note
//  Prototyped as void ft_lstiter(t_list *lst, void (*f)(void*))
//  -> lst: the address of a pointer to a node
//  -> f: the address of the function used to iterate on the list
//  -> iterates the list 'lst' and applies the function 'f' on the content of
//     each node
//  -> the memory of ’next’ must not be freed
//  -> external functs: none
//  -> return: none

#include "libft.h"

// Iterates the list 'lst' and applies 'f' on the content of each node
void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
