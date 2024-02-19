/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:37:15 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/19 17:54:28 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_itohex(int n)
{
	int				len;
	unsigned int	tempn;
	char			base[17];
	char			*str;

	len = 1;
	tempn = (unsigned int) n;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	if (n < 0)
		tempn = ~((unsigned int)(-n)) + 1;
	while (tempn / 16)
	{
		tempn /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!str)
		return (NULL);
	str[len + (n < 0)] = '\0';
	while (len--)
	{
		str[len + (n < 0)] = base[tempn % 16];
		tempn /= 16;
	}
	if (n < 0)
		str[0] = '-';
	return(str);
}
