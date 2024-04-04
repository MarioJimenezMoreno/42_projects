/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:43:42 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/01 12:52:13 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itohex(unsigned int n, char *base)
{
	int				len;
	unsigned int	tempn;
	char			*str;

	len = 1;
	tempn = n;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (tempn / 16)
	{
		tempn /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	str[len--] = '\0';
	while (n)
	{
		str[len--] = base[n % 16];
		if (len == 0)
			str[len] = base[n / 16];
		n = n / 16;
	}
	return (print_and_free(str));
}

static char	*ft_ltohex(unsigned long n, char *base)
{
	int				len;
	unsigned long	tempn;
	char			*str;

	len = 1;
	tempn = n;
	while (tempn / 16)
	{
		tempn /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (n)
	{
		str[len--] = base[n % 16];
		if (len == 0)
			str[len] = base[n / 16];
		n = n / 16;
	}
	return (str);
}

int	ft_ptoa(void *ptr)
{
	char	*str;
	char	*hex;

	if (ptr != NULL)
		hex = ft_ltohex((unsigned long) ptr, "0123456789abcdef");
	else
		hex = ft_strdup("0");
	if (!hex)
		return (-1);
	str = ft_strjoin("0x", hex);
	if (!str)
	{
		free(hex);
		return (-1);
	}
	free(hex);
	return (print_and_free(str));
}
