/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:11 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/25 20:10:31 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	place_number(unsigned int n, char *str, int i)
{
	if (n / 10)
		place_number(n / 10, str, i);
	str[i] = (n % 10) + '0';
	i++;
}

static int	calc_int_len(unsigned int n)
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

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = calc_int_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	place_number(n, str, i);
	str[len] = '\0';
	return (str);
}
