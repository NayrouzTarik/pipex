/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:59 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/10 21:03:27 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, int b, char **av, char **env)
{
	char	**path;

	(void)b;
	path = NULL;
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve(is_executable(av[3], env, path), is_cmd_composed(av[3]), env);
}

void	parent_process(int *fd, int a, char **av, char **env)
{
	char	**path;

	(void)a;
	path = NULL;
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	execve(is_executable(av[2], env, path), is_cmd_composed(av[2]), env);
}

int	main(int ac, char **av, char **env)
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	pid;
	int status;

	if (check_args(ac, av) != -1)
	{
		check_my_in_files(av, &infile);
		check_my_out_files(ac, av, &outfile);
		if (pipe(fd) == -1)
			ft_error("Pipe failed\n");
		pid = fork();
		if (pid == 0)
			child_process(fd, outfile, av, env);
		else if (pid > 0)
		{
			pid = fork();
			if (pid == 0)
				parent_process(fd, infile, av, env);
			wait(&status);
		}
		else
			ft_error("Fork failed\n");
	}
	return (0);
}
