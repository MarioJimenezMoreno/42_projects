/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:07:29 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/07 15:07:35 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int flag)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (free_buf(&s, ft_strdup("")));
	if (len > slen - start)
		len = slen - start;
	subs = (char *)malloc(sizeof(char) * len + 1);
	if (!subs)
		return (free_buf(&s, NULL));
	i = 0;
	while (i < len && start + i < slen)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	if (flag)
		free(s);
	return (subs);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (free_buf(&s1, NULL));
	i = 0;
	while (s1[i])
	{
		s3[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = ((char *)s2)[j];
		j++;
	}
	s3[i + j] = '\0';
	return (free_buf(&s1, s3));
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (free_buf(&s, NULL));
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
