/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:30:52 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/31 18:49:45 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;
	unsigned char	*u_s;

	i = 0;
	u_c = (unsigned char)c;
	u_s = (unsigned char *)s;
	while (i < n)
	{
		if (u_c == u_s[i])
			return ((void *)&u_s[i]);
		i++;
	}
	return (NULL);
}
