/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:45:00 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/22 16:00:19 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i])
	{	j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				break;
			}
			j++;
		}
		i++;
	}
	len -= i;
	if (len <= 0)
		return (trim);
	
	return (trim);
}
