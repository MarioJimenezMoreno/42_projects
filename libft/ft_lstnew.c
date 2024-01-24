/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:12:18 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/23 18:47:45 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(*node));
	if (!node)
		return (NULL)
	node->content = content;
	node->next = NULL;
	return (node);
}
