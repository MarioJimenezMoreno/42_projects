/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:58:35 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/07 16:27:39 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splits_calc(char const *s, char c, char ***str)
{
	int	i;
	int	splits;

	i = 0;
	splits = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			splits++;
		i++;
	}
	*str = (char **)malloc(sizeof(char *) * (splits + 1));
	return (splits);
}

static int	assign_str(char **str, const char *s, int len, int i)
{
	int	x;

	x = 0;
	*str = (char *)malloc(sizeof(char) * (len + 1));
	if (!*str)
		return (0);
	while (len--)
	{
		(*str)[x] = s[i - len - 1];
		x++;
	}
	(*str)[x] = '\0';
	return (1);
}

static int	splits_len(char const *s, char c, char **str)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] && s[i] != c)
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			if (!assign_str(&str[j], s, len, i))
				return (0);
			j++;
		}
		if (!s[i])
			break ;
		i++;
	}
	return (1);
}

static void	flying_free(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		splits;

	i = 0;
	if (!s)
		return (NULL);
	splits = splits_calc(s, c, &str);
	if (!str)
		return (NULL);
	if (splits)
	{
		if (!splits_len(s, c, str))
		{
			flying_free(&str);
			return (NULL);
		}
		i++;
	}
	str[splits] = NULL;
	return (str);
}
