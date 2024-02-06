/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:44:36 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/01 02:46:36 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n <= 2147483647 && n >= -2147483647)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n / 10)
			ft_putnbr_fd(n / 10, fd);
		num = (n % 10) + '0';
		write(fd, &num, 1);
	}
}
