/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:30:06 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/14 21:06:31 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**is_cmd_composed(char *av)
{
	char	**cmd;

	cmd = ft_split(av, ' ');
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}

char	*exec_cmd(char **cmd, char *path)
{
	char	*final;
	char	*final_final;

	final = ft_strjoin(path, "/");
	final_final = ft_strjoin(final, cmd[0]);
	if (access(final_final, X_OK) != -1)
	{
		free(final);
		return (final_final);
	}
	free(final);
	free(final_final);
	return (NULL);
}

char	*is_executable(char *av, char **envp, char **PATH)
{
	int		i;
	char	**cmd;
	char	*ret;

	i = 0;
	PATH = find_path(envp);
	if (!PATH)
		ft_error("Error: PATH is unseted \
		kill the terminal & rexecute\n");
	if (with_path(av) == 0)
	{
		cmd = is_cmd_composed(av);
		while (PATH[i])
		{
			ret = exec_cmd(cmd, PATH[i]);
			if (ret)
				return (ret);
			i++;
			free(ret);
		}
	}
	return (command_not_found(av), NULL);
}
