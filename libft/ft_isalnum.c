/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 17:58:01 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/24 15:15:33 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58)
		|| (c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
