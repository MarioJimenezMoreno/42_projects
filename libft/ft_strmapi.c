/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:10:17 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/24 20:21:45 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;	
	int		i;

	i = 0;	
	str =(char*)malloc(sizeof(char) * ft_strlen(s));
	if (!str)
			return (NULL);
	while (str[i])
	{
		str[i] = f(i,s[i]);
		i++;
	}
	return(str);
}
