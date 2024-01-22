/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:41:12 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/22 15:38:04 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		num;
	int 	i;

	num = ft_strlen(s) - start - 1;
	if (ft_strlen(s) - start > len)
		num = len;
	subs = (char *)malloc(sizeof(char) * num);
	if (!subs)
		return (NULL);
	i = 0;
	while (subs[i])
	{
		subs[i] = s[start - 1 + i];
		i++;
	}
	return (subs);
}
