/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:52:21 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/04 19:35:29 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	with_path(char *av)
{
	char	*args[2];

	if (ft_strchr(av, '/') != NULL)
	{
		args[0] = av;
		args[1] = NULL;
		if (execve(av, args, NULL) == -1)
			no_file_dire("No such file or directory\n");
	}
	return (0);
}
