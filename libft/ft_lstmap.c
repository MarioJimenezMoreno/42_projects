/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:52:16 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/06 05:04:10 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;

	n_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&n_list, ft_lstnew(f(lst->content)));
		if (!lst->content)
			ft_lstdelone(n_list, del);
		lst = lst->next;
	}
	return (n_list);
}
