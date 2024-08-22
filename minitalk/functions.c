#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((int *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = size * nmemb;
	ptr = (void *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb);
	return (ptr);
}

int	ft_atoi(char *nptr)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			num = num * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (sign * num);
}
