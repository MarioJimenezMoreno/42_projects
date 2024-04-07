/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:07:10 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/07 15:15:51 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*free_buf(char **buf, char *out);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len, int flag);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
#endif
