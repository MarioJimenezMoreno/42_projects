/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:58:35 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/06 10:34:38 by mariojim         ###   ########.fr       */
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
	if (splits == 0)
		return (0);
	*str = (char **)malloc(sizeof(char *) * splits);
	return (splits);
}

static void	splits_len(char const *s, char c, char ***str)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			(*str)[j] = (char *)malloc(sizeof(char) * (len + 1));
			j++;
			len = 0;
		}
		i++;
	}
}

static void	flying_free(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	fill_splits(int splits, char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (splits > 0)
	{
		j = 0;
		while (s[x] == c)
			x++;
		while (s[x] && s[x] != c)
		{
			str[i][j] = s[x];
			j++;
			x++;
		}
		str[i][j] = '\0';
		x++;
		i++;
		splits--;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		splits;

	i = 0;
	if (!s[0] || splits_calc(s, c, &str) == 0)
	{
		str = (char **)malloc(sizeof(char *) * 1);
		str[0] = NULL;
		return (str);
	}
	splits = splits_calc(s, c, &str);
	if (!str)
		return (NULL);
	splits_len(s, c, &str);
	while (str[i])
	{
		if (!str[i])
		{
			flying_free(&str);
			return (NULL);
		}
		i++;
	}
	fill_splits(splits, str, s, c);
	return (str);
}
/*int main()
{
	int i;
	char **hola = ft_split("0 0 0 3 2", ' ');
	
	i = 0;
	while (hola[i])
	{
		printf("%s - ",hola[i]);
		i++;
	}
}*/
