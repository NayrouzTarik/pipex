/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:53:59 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/04 19:06:24 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, int b, char **av, char **env)
{
	char **PATH;

	PATH = NULL;
	dup2(b, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execve(is_executable(av[3], env, PATH), is_cmd_composed(av[3]), env);
}

void	parent_process(int *fd, int a, char **av, char **env)
{
	int		status;
	char **PATH;

	PATH = NULL;
	dup2(a, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	waitpid(-1, &status, 0);
	execve(is_executable(av[2], env, PATH), is_cmd_composed(av[2]), env);
}


// int	main(int ac, char **av, char **env)
// {
// 	int		a;
// 	int		b;
// 	int		fd[2];
// 	pid_t	pid;

// 	char *o = malloc(100);
// 	if (check_args(ac, av) != -1)
// 	{
// 		a = check_my_in_files(av);
// 		b = check_my_out_files(ac, av);
// 		pipe_it(fd);
// 		pid = fork();
// 		if (pid > 0)
// 		{
// 			child_process(fd, b, av, env);
// 			atexit(func);
// 		}
// 		else if (pid == 0)
// 			parent_process(fd, a, av, env);
// 		exit(1);
// 	}
// }
