/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:36:12 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/10/05 11:52:32 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int	ft_putchar(char c);
int	ft_putstr(char *s );
int	ft_putnbr(long int n);
int	ft_printf(const char *str, ...);
int	ft_puthexlow(unsigned int n);
int	ft_puthexup(unsigned int n);
int	ft_putunsnbr(unsigned int n);
int	ft_putpointer(unsigned long n);

#endif