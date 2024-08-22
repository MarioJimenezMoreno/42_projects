#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
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
	return (s3);
}

static int	calc_sign(int n, char *str)
{
	if (n >= 0)
		return (1);
	str[0] = '-';
	if (n == -2147483648)
		str[1] = '2';
	return (-1);
}

static void	place_number(int n, char *str, int *i, int sign)
{
	if (n / 10)
		place_number(n / 10, str, i, sign);
	str[*i] = (sign * n % 10) + '0';
	(*i)++;
}

static int	calc_int_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	i = 0 + (n < 0) + (n == -2147483648);
	len = calc_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!str)
		return (NULL);
	sign = calc_sign(n, str);
	if (n == -2147483648)
		n += 2000000000;
	place_number(n, str, &i, sign);
	str[i] = '\0';
	return (str);
}
