/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:14 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/11 14:52:23 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	permission_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	no_file_dire(char *str)
{
	write(2, str, ft_strlen(str));
	exit(2);
}

void	command_not_found(char *str)
{
	write(2, "Command not found: ", 20);
	write(2, str, ft_strlen(str));
	exit(127);
}
