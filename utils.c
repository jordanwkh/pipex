/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:34:12 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/05/02 16:36:37 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(char *str)
{
	perror(str);
	exit(errno);
}

void	run_if_access(char *path, char **args, char **envp)
{
	if (access(path, X_OK) == 0)
	{
		execve(path, args, envp);
		error_msg("execve failed");
	}
}
