/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:45:00 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/06 09:17:40 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_end(char const *s1, char const *set)
{
	int	len;
	int	x;
	int	j;

	j = 0;
	x = 0;
	len = ft_strlen(s1) - 1;
	if (ft_strlen(set) == 0)
		return (j);
	while (len - j > 0)
	{
		if (s1[len - j] != set[x])
		{
			x++;
			if (!set[x])
				break ;
			continue ;
		}
		x = 0;
		j++;
	}
	return (j);
}

static size_t	trim_start(char const *s1, char const *set)
{
	int	x;
	int	i;

	i = 0;
	x = 0;
	if (ft_strlen(set) == 0)
		return (i);
	while (s1[i])
	{
		if (s1[i] != set[x])
		{
			x++;
			if (!set[x])
				break ;
			continue ;
		}
		x = 0;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	i;
	size_t	j;

	i = trim_start(s1, set);
	j = trim_end(s1, set);
	len = ft_strlen(s1) - i - j;
	if (ft_strlen(s1) == i)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	j = 0;
	while (j < len)
	{
		trim[j] = s1[i + j];
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
