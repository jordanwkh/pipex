/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 18:43:50 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/08/19 17:03:15 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*retline;
	int			read_ret;

	if (fd < 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	retline = calloc(sizeof(char), 1);
	if (!retline)
		return (NULL);
	if (*buff)
		retline = _2_the_line(buff, retline);
	while (retline && !(len_checker(retline, '\n')))
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
			free (retline);
		buff[read_ret] = '\0';
		retline = _2_the_line(buff, retline);
		if (read_ret < BUFFER_SIZE)
			break ;
	}
	buff_mover(buff);
	if (retline && *retline == '\0')
		return (free(retline), NULL);
	return (retline);
}

// 	memmove(retline, buff, len_checker(buff, '\n'));
// 	//printf("retline = |%s|\n, |%s|\n", retline, buff);
// 	//buff_check(buff);
// 	buff_mover(buff);
// 	ft_strjoin(retline, buff);
// 	return (retline);
// }

// need a file that will be read.
// need to save whats been read in line
// then read second part and maybe use strjoin of memmove if it didnt reach /n
// second part needs to be saved and needs to read further.
// welke functies heb ik nodig, strjoin, memmove, bzero, malloc/calloc. strlen?,