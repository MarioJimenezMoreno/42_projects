/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:30:43 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/06 07:34:59 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nuxt;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		nuxt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nuxt;
	}
}
