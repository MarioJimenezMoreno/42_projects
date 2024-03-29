/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:14:05 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/25 19:48:46 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_ltohex(unsigned long  n)
{
	int				len;
	unsigned long	tempn;
	char			base[17];
	char			*str;

	len = 1;
	tempn = n;
	ft_strlcpy(base, "0123456789abcdef", 17);
	while (tempn / 16)
	{
		tempn /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	while (n)
	{
		str[len--] = base[n % 16];
		if (len == 0)
			str[len] = base[n / 16];
		n = n / 16;
	}
	return(str);
}
