/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:30:06 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/31 19:01:21 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_it(int *fd)
{
	if (pipe(fd) == -1)
	{
		write(2, "Pipe failed\n", 12);
		exit(1);
	}
	return (*fd);
}

char	**is_cmd_composed(char *av)
{
	char	**cmd;

	cmd = (char **)malloc(2 * sizeof(char *));
	if (cmd == NULL)
		return (NULL);
	if (strchr(av, ' ') != NULL) //ft_strchr to change mn bead
	{
		cmd = ft_split(av, ' ');
		return (cmd);
	}
	cmd[0] = av;
	cmd[1] = NULL;
	return (cmd);
}

int	is_executable_1(int ac, char *av, char **envp)
{
	int		i;
	char	**cmd;
	char	*cmd_path;
	char	*final;
	char	*final_final;

	(void) ac;
	i = 0;
	g_my_path = find_path(envp);
	while (g_my_path[i])
	{
		cmd = is_cmd_composed(av);
		cmd_path = g_my_path[i];
		final = ft_strjoin(cmd_path, "/");
		final_final = ft_strjoin(final, cmd[0]);
		if (access(final_final, X_OK) != -1)
			execve(final_final, cmd, envp);
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (-1);
	}
	else
	{
		if (av[0] == NULL || av[1] == NULL || av[2] == NULL
			|| av[3] == NULL || av[4] == NULL)
		{
			write(2, "Error: Wrong arguments\n", 24);
			return (-1);
		}
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		a;
	int		b;
	int		fd[2];
	pid_t	pid;

	if (check_args(ac, av) != -1)
	{
		a = check_my_in_files(av);
		b = check_my_out_files(ac, av);
		pipe_it(fd);
		pid = fork();
		if (pid > 0)
		{
			dup2(b, STDOUT_FILENO);
			dup2(fd[0], STDIN_FILENO);
			close(fd[1]);
			waitpid(-1, &g_status, 0);
			is_executable_1(fd[0], av[3], env);
		}
		else if (pid == 0)
		{
			dup2(a, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			is_executable_1(fd[1], av[2], env);
		}
		exit(1);
	}
}
