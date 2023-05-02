/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 18:22:08 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/24 15:13:22 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static size_t	word_counter(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

size_t	update_len(char *s, char c)
{	
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	*ft_free(char **new, size_t i)
{
	while (i >= 0)
	{
		free(new[i]);
		i--;
	}
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{	
	char	**new;
	size_t	i;
	size_t	start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = 0;
	new = ft_calloc(word_counter(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (i < word_counter(s, c))
	{	
		while (s[start] == c)
			start++;
		len = update_len((char *)s + start, c);
		new[i] = ft_substr(s, start, len);
		if (!new[i])
			return (ft_free(new, i));
		i++;
		while (s[start] != c && s[start] != '\0')
			start++;
	}
	return (new);
}
