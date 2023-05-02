/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:48:30 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/05/02 16:40:28 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeing(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

char	*finding_path(char **envp, char *cmand)
{
	int		i;
	char	**path;
	char	*found_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			if (ft_strlen(envp[i]) < 6)
				error_msg("Path is empty");
			path = ft_split(&envp[i][5], ':');
			if (!path)
				error_msg("failed try again");
			found_path = cmand_to_path(path, cmand);
			freeing(path);
			return (found_path);
		}
		i++;
	}
	error_msg("Couldn't find PATH");
	return (NULL);
}

char	*cmand_to_path(char **found_path, char *cmand)
{
	char	*actual_path;
	int		i;
	char	*slash_cmand;

	i = 0;
	slash_cmand = ft_strjoin("/", cmand);
	if (!slash_cmand)
		return (0);
	while (found_path[i])
	{
		actual_path = ft_strjoin(found_path[i], slash_cmand);
		if (!actual_path)
			error_msg("Malloc failed");
		if (access(actual_path, X_OK) == 0)
		{
			free (slash_cmand);
			return (actual_path);
		}
		free (actual_path);
		i++;
	}
	error_msg("Invalid command");
	free (slash_cmand);
	return (0);
}
