/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:02:57 by jhoekstr      #+#    #+#                 */
/*   Updated: 2023/05/02 16:43:54 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	forking_safely(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_msg("fork failed");
	return (pid);
}

void	executing(char *cmand, char **envp)
{
	char	**args;
	char	*path;
	char	*new_path;

	args = ft_split(cmand, ' ');
	path = args[0];
	if (strchr(cmand, '/'))
	{
		run_if_access(path, args, envp);
	}
	new_path = finding_path(envp, path);
	execve(new_path, args, envp);
	error_msg("Executable not found, or no permissions");
}

void	child_one(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		error_msg("Can't open file");
	close(pipe_fd[0]);
	if (dup2(file_fd, 0) == -1 || dup2(pipe_fd[1], 1) == -1)
		error_msg("dup2 failed");
	close(pipe_fd[1]);
	executing(argv[2], envp);
}

void	child_two(char **argv, char **envp, int *pipe_fd)
{
	int	file_fd;

	file_fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (file_fd == -1)
		error_msg("Can't open file");
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], 0) == -1 || dup2(file_fd, 1) == -1)
		error_msg("dup2 failed");
	close(pipe_fd[0]);
	executing(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		w_status;

	if (argc != 5)
		error_msg("Not enough arguments or too many");
	if (pipe(pipe_fd) == -1)
		error_msg ("Pipe fails");
	pid_1 = forking_safely();
	if (pid_1 == 0)
		child_one(argv, envp, pipe_fd);
	pid_2 = forking_safely();
	if (pid_2 == 0)
		child_two(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid_1, &w_status, 0);
	waitpid(pid_2, &w_status, 0);
	if (WIFEXITED(w_status))
		exit(WIFEXITED(w_status));
	exit(EXIT_FAILURE);
}
