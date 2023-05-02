/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 18:00:27 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/07 16:29:07 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	intlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	nb;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = intlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb /= 10;
	}
	return (str);
}
