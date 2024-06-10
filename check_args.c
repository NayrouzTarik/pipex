/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:31:42 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/09 23:42:14 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int ac, char **av)
{
	char	**fcmd;
	char	**scmd;

	if (ac != 5)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (-1);
	}
	fcmd = is_cmd_composed(av[2]);
	scmd = is_cmd_composed(av[3]);
	if (fcmd[0] == NULL || scmd[0] == NULL)
	{
		write(2, "Error: Memory allocation failed\n", 33);
		free2d(fcmd);
		free2d(scmd);
		return (-1);
	}
	free2d(fcmd);
	free2d(scmd);
	return (0);
}
