/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:55:33 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/31 18:43:37 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		if (n == 1)
			break ;
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
