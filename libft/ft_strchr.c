/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:03:24 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/26 18:34:32 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	
	i = 0;
	ptr = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			return (ptr);	
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}
