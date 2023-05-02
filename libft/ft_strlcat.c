/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 18:24:00 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/22 15:32:39 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen((char *)dst);
	lens = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (lens);
	if (dstsize <= lend)
		return (lens + dstsize);
	while (src[i] != '\0' && (lend + i) < (dstsize - 1))
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
