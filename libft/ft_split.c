/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:58:35 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/23 20:45:11 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void splits_len(char const *s, char c, char **str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			str[j] =(char *)malloc(sizeof(char) * (len));
			if (!str[j])
				return (NULL);
			j++;
			len = -1;
		}
		i++;
		len++;
	}
}

void splits_calc(char const *s, char c, char **str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			len++;
		if (!s[i] && s[i] != c)
			len++;
	}
	str =(char **)malloc(sizeof(char *) * len);
	if (!str)
		return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	splits_calc(s, c, str);
	splits_len(s, c ,str);
	
}
