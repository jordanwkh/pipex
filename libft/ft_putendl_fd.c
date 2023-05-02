/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 17:56:36 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/01/28 15:20:10 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	end;

	end = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &end, 1);
}
