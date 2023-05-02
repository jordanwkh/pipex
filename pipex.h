/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:05:09 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/05/02 15:55:03 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>

void	error_msg(char *str);
char	*finding_path(char **envp, char *cmand);
char	*cmand_to_path(char **found_path, char *cmand);
void	run_if_access(char *path, char **args, char **envp);

#endif