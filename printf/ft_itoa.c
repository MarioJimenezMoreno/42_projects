/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:11 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/01 12:50:19 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	i = 0 + (n < 0) + (n == -2147483648);
	len = calc_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!str)
		return (-1);
	sign = calc_sign(n, str);
	if (n == -2147483648)
		n += 2000000000;
	place_number(n, str, &i, sign);
	str[i] = '\0';
	return (print_and_free(str));
}
