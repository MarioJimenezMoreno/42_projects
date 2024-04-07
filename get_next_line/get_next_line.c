/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:02:50 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/07 15:19:51 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*free_buf(char **buf, char *out)
{
	free(*buf);
	*buf = NULL;
	return (out);
}

static char	*read_buffer(int fd, char **stash)
{
	char	*buf;
	int		seen;

	seen = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (seen > 0)
	{
		if (ft_strchr(*stash, '\n'))
			break ;
		seen = read(fd, buf, BUFFER_SIZE);
		if (seen == -1)
			return (free_buf(&buf, NULL));
		else if (seen == 0)
			break ;
		buf[seen] = '\0';
		*stash = ft_strjoin(*stash, buf);
		if (!*(stash))
			return (free_buf(&buf, NULL));
	}
	return (free_buf(&buf, "ok"));
}

char	*get_next_line(int fd)
{
	size_t		i;
	static char	*stash;
	char		*line;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!read_buffer(fd, &stash))
		return (free_buf(&stash, NULL));
	if (!ft_strlen(stash))
		return (free_buf(&stash, NULL));
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_substr(stash, 0, i + 1, 0);
	if (!line)
		return (NULL);
	stash = ft_substr(stash, i + 1, ft_strlen(stash) - i, 1);
	if (!stash)
		return (NULL);
	return (line);
}
