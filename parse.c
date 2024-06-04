/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:45 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/04 19:42:35 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

int	check_my_in_files(char **av)
{
	int	fd_in;

	fd_in = open(av[1], O_RDONLY);
	if (access(av[1], F_OK) != -1)
	{
		if (access(av[1], R_OK) != -1)
		{
			if (access(av[1], X_OK) != -1)
				fd_in = open(av[1], O_RDONLY);
			else
				ft_error("\033[1;31mPermission denied \n");
		}
		else
			ft_error("\033[1;31mPermission denied \n");
	}
	else
		no_file_dire("No such file or directory ");
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
				permission_error("\033[1;31mPermission denied \n");
		}
		else
			permission_error("\033[1;31mPermission denied \n");
	}
	else
		no_file_dire("No such file or directory ");
	return (fd_out);
}
