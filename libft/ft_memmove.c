/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:01:03 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:32:27 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;
	int		i;
	
	i = 0;
	while (i < n)
	{
		temp[i] = src[i]
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = temp[i];
		i++;
	}
}
