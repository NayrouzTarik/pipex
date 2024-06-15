/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:45 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/14 23:55:41 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	**find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

void	check_my_in_files(char **av)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if ((infile) == -1)
	{
		if (access(av[1], F_OK) == -1)
			no_file_dire("No such file or directory\n");
		else if (access(av[1], R_OK) == -1)
			permission_error("\033[1;31mPermission denied\n");
		else
			ft_error("Open() has failed\n");
	}
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("dup2() has failed\n");
	close(infile);
}

void	check_my_out_files(int ac, char **av)
{
	int	outfile;

	outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if ((outfile) == -1)
	{
		if (access(av[ac - 1], W_OK) == -1)
			permission_error("\033[1;31mPermission denied \n");
		else
			ft_error("Open() has failed\n");
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("dup2() has failed\n");
	close(outfile);
}
