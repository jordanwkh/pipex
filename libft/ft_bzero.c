/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:45:18 by jhoekstr      #+#    #+#                 */
/*   Updated: 2021/12/14 17:45:33 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*c;

	c = s;
	while (n != 0)
	{
		*c = 0;
		c++;
		n--;
	}
	return (0);
}
