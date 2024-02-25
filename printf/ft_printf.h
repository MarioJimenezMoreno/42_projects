/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:46:27 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/25 19:44:27 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_stolower(char *s);
char	*ft_itohex(unsigned int n);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ltohex(unsigned long n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_ptoa(void *ptr);
int		ft_printf(char const *s, ...);
char	*ft_strdup(const char *s);

#endif
