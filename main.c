/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:59 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/14 23:28:35 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **av, char **env)
{
	char	**path;

	path = NULL;
	if (dup2(fd[1], 1) == -1)
		ft_error("dup2() failed\n");
	close(fd[1]);
	close(fd[0]);
	execve(is_executable(av[2], env, path), is_cmd_composed(av[2]), env);
}

void	second_child(int *fd, char **av, char **env)
{
	char	**path;

	path = NULL;
	if (dup2(fd[0], 0) == -1)
		ft_error("dup2() failed\n");
	close(fd[0]);
	close(fd[1]);
	execve(is_executable(av[3], env, path), is_cmd_composed(av[3]), env);
}

void	parent_process(int *fd, int status, pid_t pid, pid_t pid2)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status, 0);
}

void	my_fork(pid_t *pid)
{
	*pid = fork();
	if (*pid == -1)
		ft_error("Fork failed\n");
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	t_pipex	pipex;

	if (check_args(ac, av) == -1)
		return (1);
	else if (check_args(ac, av) != -1)
	{
		check_my_in_files(av);
		check_my_out_files(ac, av);
		if (pipe(fd) == -1)
			ft_error("Pipe failed\n");
		my_fork(&pipex.pid);
		if (pipex.pid == 0)
			child_process(fd, av, env);
		else if (pipex.pid > 0)
		{
			my_fork(&pipex.pid2);
			if (pipex.pid2 == 0)
				second_child(fd, av, env);
			else
				parent_process(fd, pipex.status, pipex.pid, pipex.pid2);
		}
	}
	return (0);
}
