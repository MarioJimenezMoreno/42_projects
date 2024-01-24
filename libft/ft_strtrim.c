/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:45:00 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/23 18:10:26 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void trim_end(char const *s1, char const *set, int i, int j)
{
	while (s1[len - k - 1])
	{
		if (s1[len - k - 1] != set[j])
		{
			j++;
			if (!set[j])
				break;
			continue;
		}
		j = 0;
		k++;
	}
}

static void	trim_start(char const *s1, char const *set, int i, int j)
{
	while (s1[i])
	{
		if (s1[i] != set[j])
		{
			j++;
			if (!set[j])
				break;
			continue;
		}
		j = 0;
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		len;
	int		i;
	int		j;
	int		k;

	len = ft_strlen(s1);
	i = 0;
	trim_start(s1, set, &i, &j);
	trim_end(s1, set, &k, &j);
	if (len - i - 1 == 0)
		return (trim);
	
	return (trim);
}
