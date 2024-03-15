/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:02:50 by mariojim          #+#    #+#             */
/*   Updated: 2024/03/14 21:55:02 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*buf;
	int			i;
	static char	*stash;	
	char		*line;	

	i = 0;
	buf = (char *)malloc(sizeof(char) * 11);
	if (!stash)
		stash = ft_strdup("");
	while (ft_strchr(stash, '\n') == NULL)
	{
		if (read(fd, buf, 10) == -1)
		{
			free(buf);
			return (NULL);
		}
		stash = ft_strjoin(stash, buf);
	}
	while (stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i);
	stash = ft_substr(stash, i + 1, 10);
	line[i + 1] = '\0';
	return (line);
}
/*int main()
{
	int fd;
	
	fd = open("fd.txt", O_RDONLY);
	printf("PRIMERA: %s\n", get_next_line(fd));
	printf("SEGUNDA: %s\n", get_next_line(fd));
	printf("TERCERA: %s\n", get_next_line(fd));
}*/
