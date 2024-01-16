/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:18:04 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/15 00:58:21 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && size > 0)
	{
		i++;
		size--;
	}
	while (src[j] != '\0' && size > 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	while (size > 0)
	{
		dest[i] = '\0';
		size--;
	}
	return (i);
}
