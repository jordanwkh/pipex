/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:45:38 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/04/06 20:28:34 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ('\t') || c == ('\n') || c == ('\v')
		|| c == ('\f') || c == ('\r') || c == (' '))
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		sign;

	n = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
	}
	if (str[i] == ('-') || str[i] == ('+'))
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
		if (n < INT_MIN || n > INT_MAX)
			return (((long)(INT_MAX)) + 1);
	}
	return (n * sign);
}
