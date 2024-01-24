/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:11 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/24 20:07:07 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int calc_sign(int n, char *str)
{
	if (n < 0)
	{
		str[0] = '-'; 
		return (-1);
	}
	return (1);
}

static void place_number(int n, char *str, int *i, int sign)
{
	if (n / 10)
		place_number(n / 10, str, i, sign);
	str[*i] = (sign * n % 10) + '0';
	(*i)++;
}

static void	calc_int_len(int n, int *len)
{
	while (n / 10)
	{
		n = n / 10;
		(*len)++;
	}
}

char	*ft_itoa(int n)
{
	char *str;
	int len;	
	int i;
	
	i = 0 + (n < 0);
	len = 1;
	calc_int_len(n, &len);
	str = (char*)malloc(sizeof(char) * (len + (n < 0)));
	place_number(n, str, &i, calc_sign(n, str));
	return (str);
}
