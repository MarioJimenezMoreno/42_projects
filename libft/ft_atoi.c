/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:22 by mariojim          #+#    #+#             */
/*   Updated: 2024/01/16 18:39:05 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *nptr)
{
	int		num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 0;
	while (nptr[i] == ' ')
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	if (sign % 2 != 0)
		return (-num);
	return (num);
}
