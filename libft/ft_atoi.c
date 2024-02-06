/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:08:22 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/01 00:45:33 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *nptr)
{
	int	num;
	int	sign;
	int	i;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			num = num * 10 + (nptr[i] - '0');
		else
			break ;
		i++;
	}
	return (sign * num);
}
