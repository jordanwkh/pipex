/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 18:44:34 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/10/05 11:52:08 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char		*get_next_line(int fd);
int			len_checker(char *str, char c);
//static	int	lf_newline(char *b);
//char		*str_joining(char *retline, char *buff);
//char		*ft_strjoin(char *retline, char *buff);
void		buff_check(char *buff);
void		buff_mover(char *buff);
void		*calloc(size_t count, size_t size);
char		*_2_the_line(char *buff, char *retline);
#endif