/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:52:16 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/07 16:58:57 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*buffer;
	t_list	*cont;

	n_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		buffer = ft_lstnew(cont);
		if (!buffer)
		{
			del(cont);
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, buffer);
		lst = lst->next;
	}
	return (n_list);
}
