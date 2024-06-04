/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:30:06 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/04 19:43:10 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void free2d(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	pipe_it(int *fd)
{
	if (pipe(fd) == -1)
		ft_error("Pipe failed\n");
	return (*fd);
}

char	**is_cmd_composed(char *av)
{
	char	**cmd;
	char **temp;

	temp = NULL;
	cmd = (char **)malloc(2 * sizeof(char *));
	if (cmd == NULL)
		return (NULL);
	if (ft_strchr(av, ' ') != NULL)
	{
		temp = ft_split(av, ' ');
		free(cmd); 
		return (temp);
	}
	cmd[0] = av;
	cmd[1] = NULL;
	return (cmd);
}

char	*is_executable(char *av, char **envp, char** PATH)
{
	int		i;
	char	**cmd;
	char	*cmd_path;
	char	*final;
	char	*final_final;

	i = 0;
	PATH = find_path(envp);
	if (!PATH)
	{
		perror("Error: PATH not found\n");
		return NULL;//alocating PATH
	}
	if (with_path(av) == 0)
	{
		cmd = is_cmd_composed(av);
		while (PATH[i])
		{
			cmd_path = PATH[i];
			final = ft_strjoin(cmd_path, "/");
			final_final = ft_strjoin(final, cmd[0]);
			if (access(final_final, X_OK) != -1)
			{
				free2d(cmd);
				free(final);
				return final_final;
			}
			i++;
			free(cmd_path);
			free(final);
			free(final_final);
		}
	}
	return (command_not_found(av), NULL);
}

int	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		exit(1);
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
