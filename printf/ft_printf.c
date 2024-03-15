/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:01 by mariojim          #+#    #+#             */
/*   Updated: 2024/03/15 16:05:56 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	
	c = '%';
	str = NULL;
	if (ch == 'c')
		c = va_arg(args, int);
	else if (ch == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (ch == 'd' || ch == 'i')		
		str = ft_itoa(va_arg(args, int));
	else if (ch == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	else if (ch == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (ch == 'x')
		str = ft_stolower(ft_itohex(va_arg(args, unsigned int)));
	else if (ch == 'X')
		str = ft_itohex(va_arg(args, int));
	else if (ch != '%')
		return (0);
	if (str == NULL)
		return(ft_putchar_fd(c, 1));
	else
		return(print_and_free(str));
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		letters;
	va_list args;
	
	i = 0;
	letters = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%')
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
/*int main()
{
	char *s = "hola";
	printf("%s  %d %u %p %x %X %%\n",s,-10,-10,s,-10,-10);
	ft_printf("%s  %d %u %p %x %X %%",s,-10,-10,s,-10,-10);
}*/
