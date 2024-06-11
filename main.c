/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:59 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/11 22:48:29 by ntarik           ###   ########.fr       */
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

void	parent_process(int *fd, char **av, char **env)
{
	char	**path;

	path = NULL;
	if (dup2(fd[0], 0) == -1)
		ft_error("dup2() failed\n");
	close(fd[0]);
	close(fd[1]);
	execve(is_executable(av[3], env, path), is_cmd_composed(av[3]), env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (check_args(ac, av) == -1)
		return (1);
	else if (check_args(ac, av) != -1)
	{
		check_my_in_files(av);
		check_my_out_files(ac, av);
		if (pipe(fd) == -1)
			ft_error("Pipe failed\n");
		pid = fork();
		if (pid == 0)
			child_process(fd, av, env);
		else if (fork() == 0)
			parent_process(fd, av, env);
		wait(&status);
	}
	return (0);
}
