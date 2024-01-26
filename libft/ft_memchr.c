/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:30:52 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/26 16:13:22 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char uc;
	void *ptr;
	
	uc = c;
	i = 0;
	while (i < n && ((char *)s)[i])
	{
		if (uc == ((char *)s)[i])
		{
			ptr = ((char *)s)[i];
			return (ptr);
		}
	}
	return (NULL);
}
