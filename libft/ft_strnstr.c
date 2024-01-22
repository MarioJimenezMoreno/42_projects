/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:12:28 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:37:59 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	j = 0;
	if (*little == '\0')
		return (big);
	while (*big != '\0' && j < len)
	{
		i = 0;
		while (big[i] == little[i])
		{
			i++;
			if (little[i] == '\0')
				return (big);
		}
		j++;
		big++;
	}
	return (NULL);
}
