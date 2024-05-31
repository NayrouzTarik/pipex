/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:07:36 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/31 18:26:25 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	counter(const char *str, char sep)
{
	int	counter;
	int	flag;

	counter = 0;
	flag = 0;
	while (*str)
	{
		if (*str != sep && flag == 0)
		{
			flag = 1;
			counter++;
		}
		else if (*str == sep)
			flag = 0;
		str++;
	}
	return (counter);
}

static char	**allocate_memory(int word_count)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_calloc((word_count + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= word_count)
	{
		res[i] = NULL;
		i++;
	}
	return (res);
}

static void	free_towdim(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static void	copy_word(char **res, const char *str, char c, int i)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	res[i] = ft_substr(str, 0, len);
	if (res[i] == NULL)
		free_towdim(res);
}

char	**ft_split(const char *str, char c)
{
	int		word_c;
	char	**result;
	int		i;

	if (!str)
		return (NULL);
	word_c = counter(str, c);
	result = allocate_memory(word_c);
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_c)
	{
		while (*str && *str == c)
			str++;
		copy_word(result, str, c, i++);
		str += ft_strlen(result[i - 1]);
	}
	result[word_c] = NULL;
	return (result);
}
