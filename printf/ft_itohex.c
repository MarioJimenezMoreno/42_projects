/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:37:15 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/14 19:52:15 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_itohex(int n)
{
	int		len;
	int		tempn;
	char	base[17];
	char	*str;

	len = 1;
	tempn = n;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
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
