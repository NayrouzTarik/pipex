/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:45 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/02 18:03:04 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A'
			&& env[i][2] == 'T' && env[i][3] == 'H')
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

int	check_my_in_files(char **av)
{
	int	fd_in ;

	if (access(av[1], F_OK) != -1)
	{
		if (access(av[1], R_OK) != -1)
		{
			if (access(av[1], X_OK) != -1)
				fd_in = open(av[1], O_RDONLY);
			else
			{
				write(2, "Permission denied \n", 18);
				exit(1);
			}
		}
		else
		{
			write(2, "Permission denied \n", 18);
			exit(1);
		}
	}
	else
	{
		write(2, "No such file or directory \n", 26);
		exit(1);
	}
	return (fd_in);
}

int	check_my_out_files(int ac, char **av)
{
	int	fd_out ;

	fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (access(av[ac - 1], F_OK) != -1)
	{
		if (access(av[ac - 1], R_OK) != -1)
		{
			if (access(av[ac - 1], X_OK) != -1)
			{
				write(2, "Permission denied 1\n", 18);
				exit(1);
			}
		}
		else
		{
			write(2, "Permission denied 2\n", 18);
			exit(1);
		}
	}
	else
	{
		write(2, "No such file or directory\n", 26);
		exit(1);
	}
	return (fd_out);
}
