/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:01:03 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/25 20:55:14 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;
	size_t		i;

	temp =(void *)malloc(sizeof(char) * n);	
	i = 0;
	while (i < n)
	{
		((char *)temp)[i] =((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] =((char *)temp)[i];
		i++;
	}
	return (dest);
}
