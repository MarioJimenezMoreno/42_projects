/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:18:04 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/31 18:21:47 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (d_len + 1 > size)
		return (size + s_len);
	if (d_len + 1 < size)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
	}
	dst[i] = '\0';
	return (s_len + d_len);
}
