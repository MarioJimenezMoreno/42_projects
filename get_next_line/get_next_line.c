/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:02:50 by mariojim          #+#    #+#             */
/*   Updated: 2024/03/15 18:38:36 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int read_buffer(int fd, char **stash)
{
	char	*buf;
	int		seen;

	seen = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (seen > 0)
	{
		seen = read(fd, buf, BUFFER_SIZE);
		if (seen == -1)
		{
			free(*stash);
			return (0);
		}
		else if (seen == 0)
		{
			free(buf);
			break ;
		}
		*stash = ft_strjoin(*stash, buf);
		printf("Stash:%s\n", *stash);
		if (!(*stash))
			return (0);
		if (ft_strchr(*stash, '\n'))
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*stash;
	char		*line;

	i = 0;
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!read_buffer(fd, &stash))
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_substr(stash, 0, i + 1);
	if (!line)
		return (NULL);
	stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	return (line);
}
/*
int main()
{
	int fd;
	
	fd = open("fd.txt", O_RDONLY);
	printf("PRIMERA: %s\n", get_next_line(fd));
	printf("SEGUNDA: %s\n", get_next_line(fd));
	printf("TERCERA: %s\n", get_next_line(fd));
}*/
