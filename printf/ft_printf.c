/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:01 by mariojim          #+#    #+#             */
/*   Updated: 2024/04/01 12:47:06 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_and_free(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_putchar_fd(str[i], 1) != 1)
		{
			free(str);
			return (-1);
		}
		i++;
	}
	free(str);
	return (i);
}

static int	manage_letter(char const ch, va_list args)
{
	int		str;
	char	c;

	c = '%';
	str = 0;
	if (ch == 'c')
		str = ft_putchar_fd(va_arg(args, int), 1);
	else if (ch == 's')
		str = ft_putstr_fd(va_arg(args, char *), 1);
	else if (ch == 'd' || ch == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (ch == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (ch == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (ch == 'x')
		str = ft_itohex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (ch == 'X')
		str = ft_itohex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (ch == '%')
		return (ft_putchar_fd(c, 1));
	else
		return (0);
	return (str);
}

static int	sort_letters(va_list args, char const *s, int *letters, int *i)
{
	int		temp;

	if (s[*i] == '%')
	{
		temp = manage_letter(s[*i + 1], args);
		if (temp == -1)
			return (-1);
		*letters += temp;
		(*i)++;
	}
	else
	{
		if (ft_putchar_fd(s[*i], 1) != 1)
			return (-1);
		(*letters)++;
	}
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		letters;
	va_list	args;

	i = 0;
	letters = 0;
	va_start(args, s);
	while (s[i])
	{
		if (sort_letters(args, s, &letters, &i) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (letters);
}
