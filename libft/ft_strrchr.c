/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:15:43 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:36:24 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			*ptr = s[i];
		}	
		i++;
	}
	if (c == '\0')
	{
		*ptr = s[i];
		return (ptr);
	}
	return (NULL);	
}
