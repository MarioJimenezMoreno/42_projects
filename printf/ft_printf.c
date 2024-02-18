/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariojim <mariojim@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:51:01 by mariojim          #+#    #+#             */
/*   Updated: 2024/02/14 19:57:12 by mariojim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

static void print_and_free(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		free(str[i]);
		i++;
	}
}
static void	manage_letter(char const ch, va_list args)
{
	char	*str;
	char	c;
	
	c = '%';
	str = NULL;
	if (ch == 'c')
		c = va_arg(args, int);
	else if (ch == 's')
		str = va_arg(args, char *);
	else if (ch == 'd' || ch == 'i')		
		str = ft_itoa(va_arg(args, int));
	else if (ch == 'u')
		str = ft_itoa(va_arg(args, unsigned int));
	else if (ch == 'p')
		str = ft_ptoa(va_arg(args, void *));
	else if (ch == 'x')
		str = ft_tolower(ft_itohex(va_arg(args, int)));
	else if (ch == 'X')
		str = ft_itohex(va_arg(args, int));
	if (str == NULL)
		ft_putchar_fd(c, 1);
	else
		print_and_free()
}

void	ft_printf(char const *s, ...)
{
	int	i;
	int	x;
	va_list args;

	i = 0;
	x = 0;
	va_start(args, s);
	while(s[i])
	{
		if(s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' 
			|| s[i + 1] == 'p' || s[i + 1] == 'd' || s[i + 1] == 'i'
			|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
			|| s[i + 1] == '%'))
		{
			manage_letter(s[i + 1],args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(args);
}
int main()
{
	char Char = 'Z';
	char *String = "Hola";
	void *Puntero = NULL;
	int Digito = -69;

	ft_printf("Char: %c\nString: %s\n", Char, String);
	ft_printf("Puntero: %p\nDigitos: %d y %i\n", Puntero, Digito, Digito);
	ft_printf("Unsigned: %u\nLowerHex: %x\n", Digito, Hexnum);
	ft_printf("UpperHex: %x\nPercentile: %%", Hexnum);
}
