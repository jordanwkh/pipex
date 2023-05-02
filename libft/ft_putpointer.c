/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 17:11:58 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/07/20 17:30:14 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n)
{
	char	*hexlower;

	hexlower = "0123456789abcdef";
	if (n > 15)
		return (ft_putpointer(n / 16) + ft_putpointer(n % 16));
	return (write(1, &hexlower[n], 1));
}
