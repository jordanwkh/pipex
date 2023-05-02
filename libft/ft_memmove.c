/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 18:24:53 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/24 15:14:02 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	if (src > dst)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}	
	return (dst);
}
