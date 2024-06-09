/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:31:42 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/09 20:32:43 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
