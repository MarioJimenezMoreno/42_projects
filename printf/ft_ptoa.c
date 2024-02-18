/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:58:34 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/14 18:06:48 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char *ft_ptoa(void *ptr)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * ((sizeof(void *) * 2) + 3));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	i = 2;
	while (i < (sizeof(void *) * 2))
	{
		int shift = ((sizeof(void *) * 2) - 1 - (i - 2)) * 4;
	}
	str[i] = '\0';
	return(str);
}
int main()
{
	char *ptr;
	char num = '5';
	
	ptr = &num;
	printf("%p\n",ptr);
	printf("%s\n", ft_ptoa(ptr));
}
