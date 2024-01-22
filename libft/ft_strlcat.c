/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:18:04 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:34:00 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	while (src[j] != '\0' && size > 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	while (size > 0)
	{
		dst[i] = '\0';
		size--;
	}
	return (i);
}
