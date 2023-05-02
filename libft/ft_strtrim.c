/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 18:22:50 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/25 18:32:36 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	char	*rtn;

	i = 0;
	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	while (s1[i] && ft_inset(set, s1[i]))
	{
		i++;
	}
	while (l > 0 && ft_inset(set, s1[l - 1]))
	{
		l--;
	}
	rtn = ft_substr(s1, i, l - i);
	if (!rtn)
		return (NULL);
	return (rtn);
}
