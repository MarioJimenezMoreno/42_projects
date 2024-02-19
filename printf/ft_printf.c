/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:01 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/19 17:21:49 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_and_free(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

static int	manage_letter(char const ch, va_list args)
{
	char	*str;
	char	c;
	int		i;
	
	i = 0;
	c = '%';
	str = NULL;
	if (ch == 'c')
		c = va_arg(args, int);
	else if (ch == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (ch == 'd' || ch == 'i')		
		str = ft_itoa(va_arg(args, int));
	else if (ch == 'u')
		str = ft_itoa(va_arg(args, unsigned int));
	else if (ch == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (ch == 'x')
	{
		str = ft_itohex(va_arg(args, int));
		while(str[i++])
			ft_tolower(str[i]);
	}
	else if (ch == 'X')
		str = ft_itohex(va_arg(args, int));
	if (str == NULL)
		return(ft_putchar_fd(c, 1));
	else
		return(print_and_free(str));
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		x;
	int		letters;
	va_list args;
	
	i = 0;
	x = 0;
	letters = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' 
			|| s[i + 1] == 'p' || s[i + 1] == 'd' || s[i + 1] == 'i'
			|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
			|| s[i + 1] == '%'))
		{
			letters += manage_letter(s[i + 1],args);
			i += 2;
		}
		else
		{
			letters += ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (letters);
}
