/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 18:02:26 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/24 15:14:43 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{	
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}
