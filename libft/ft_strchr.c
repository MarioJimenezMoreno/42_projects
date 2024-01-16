/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 01:03:24 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/15 01:18:53 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			*ptr = s[i];
			return (ptr);
		}	
		i++;
	}
	if (c == '\0')
	{
		*ptr = s[i];
		return (ptr);
	}
	return (NULL);
}
