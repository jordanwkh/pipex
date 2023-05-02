/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 18:44:18 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/09/05 15:03:52 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_checker(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\n')
	{
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (i + 1);
			i++;
		}		
		return (0);
	}
	else
		while (str[i] != '\0')
			i++;
	return (i);
}

void	buff_check(char *buff)
{
	int	i;

	i = 0;
	if (buff[len_checker(buff, '\n')] == '\0')
	{
		while (i < BUFFER_SIZE)
		{
			buff[i] = '\0';
			i++;
		}	
		return ;
	}
	while (i <= len_checker(buff, '\0') - len_checker(buff, '\n'))
	{
		buff[i] = buff[len_checker(buff, '\n') + i];
		i++;
	}
	buff[i] = '\0';
	return ;
}

void	buff_mover(char *buff)
{
	size_t		i;
	size_t		buff_nl;
	size_t		buff_done;

	buff_nl = len_checker(buff, '\n');
	buff_done = len_checker(buff, '\0');
	if (buff_nl == 0)
	{
		buff[0] = '\0';
		return ;
	}
	i = 0;
	while (i <= (buff_done - buff_nl))
	{
		buff[i] = buff[buff_nl + i];
		i++;
	}
	buff[i] = '\0';
	return ;
}

void	*calloc(size_t count, size_t size)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc (count * size);
	if (str == 0)
		return (NULL);
	size = size * count;
	while (size > 0)
	{
		str[j] = i;
		size--;
		j++;
	}
	return (str);
}

char	*_2_the_line(char *buff, char *retline)
{
	int		retline_len;
	int		buff_len;
	char	*temp;

	retline_len = len_checker(retline, '\0');
	buff_len = len_checker(buff, '\n');
	if (buff_len == 0)
		buff_len = len_checker(buff, '\0');
	temp = calloc(sizeof(char), (retline_len + buff_len + 1));
	if (!temp)
		return (NULL);
	temp[retline_len + buff_len] = '\0';
	while (buff_len > 0)
	{
		buff_len--;
		temp[retline_len + buff_len] = buff[buff_len];
	}
	while (retline_len > 0)
	{
		retline_len--;
		temp[retline_len] = retline[retline_len];
	}
	free (retline);
	return (temp);
}

//
// 	read(fd, buff, BUFFER_SIZE);
// 	retline = calloc(sizeof(char), BUFFER_SIZE);
// 	memmove(retline, buff, len_checker(buff, '\n'));
// 	//printf("retline = |%s|\n, |%s|\n", retline, buff);
// 	//buff_check(buff);
// 	buff_mover(buff);
// 	ft_strjoin(retline, buff);
// 	return (retline);
// }
