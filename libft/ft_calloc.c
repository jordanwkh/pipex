/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:45:02 by jhoekstr      #+#    #+#                 */
/*   Updated: 2021/12/14 17:45:07 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	s;
	void	*ptr;

	s = count * size;
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, s);
	return (ptr);
}
