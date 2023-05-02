/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 14:28:49 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/07/20 17:14:07 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	checker(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2) + ft_putpointer(va_arg(arg, unsigned long)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putunsnbr(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_puthexlow(va_arg(arg, unsigned long)));
	else if (c == 'X')
		return (ft_puthexup(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else
		{
			i++;
			len += checker(arg, str[i]);
		}
		i++;
	}
	va_end(arg);
	return (len);
}
