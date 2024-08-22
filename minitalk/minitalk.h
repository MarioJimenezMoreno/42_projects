#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_atoi(char *nptr);
char*	ft_itoa(int n);
char*	ft_strjoin(char const *s1, char const *s2);
#endif
