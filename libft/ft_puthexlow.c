/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexlow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/13 18:58:35 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/07/20 17:08:08 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(unsigned int n)
{
	char	*hexlower;

	hexlower = "0123456789abcdef";
	if (n > 15)
		return (ft_puthexlow(n / 16) + ft_puthexlow(n % 16));
	return (write(1, &hexlower[n], 1));
}
