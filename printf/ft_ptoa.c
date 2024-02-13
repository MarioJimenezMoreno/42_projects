/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:58:34 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/13 00:00:53 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_ptoa(void *ptr)
{
	char	*str;
	int		len;

	len = ft_strlen(&ptr);
	str = (char *)malloc(sizeof(char) * len + 1);
	
	return(str);
}
