/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/14 17:40:09 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/07/14 18:31:12 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexup(unsigned int n)
{
	char	*hexupper;

	hexupper = "0123456789ABCDEF";
	if (n > 15)
		return (ft_puthexup(n / 16) + ft_puthexup(n % 16));
	return (write(1, &hexupper[n], 1));
}
