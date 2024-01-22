/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:30:52 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:37:36 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;
	unsigned char uc;
	void *ptr;

	uc = c;
	i = 0;
	while (i < n && s[i])
	{
		if (uc == s[i])
		{
			ptr = s[i];
			return (ptr);
		}
	}
	return (NULL);
}
