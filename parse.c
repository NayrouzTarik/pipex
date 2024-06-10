/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:45 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/10 21:02:39 by ntarik           ###   ########.fr       */
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

void	check_my_in_files(char **av, int *infile)
{
	*infile = open(av[1], O_RDONLY);
	if ((*infile) < 0)
		ft_error("");
	// if (access(av[1], F_OK) == -1)
	// 	no_file_dire("No such file or directory ");
	// if (access(av[1], R_OK) == -1)
	// 	ft_error("\033[1;31mPermission denied \n");
	if (dup2(*infile, 0) < 0)
		ft_error("");
}

void	check_my_out_files(int ac, char **av, int *outfile)
{
	*outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if ((*outfile) < 0)
		ft_error("");
	// if (access(av[ac - 1], F_OK) != -1)
	// 	no_file_dire("No such file or directory ");
	// if (access(av[ac - 1], R_OK | W_OK) == -1)
	// 	permission_error("\033[1;31mPermission denied \n");
	if (dup2(*outfile, 1) < 0)
		ft_error("");
}
