/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:58:34 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/22 18:29:12 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_ptoa(void *ptr)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * ((sizeof(void *) * 2) + 3));
	if (!str)
		return (NULL);
	str  = ft_strjoin("0x", ft_ltohex((unsigned long)ptr));
	return(str);
}
