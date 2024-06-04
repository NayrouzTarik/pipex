/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:06:59 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/03 10:50:27 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		lenght;
	int		i;

	i = 0;
	lenght = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (lenght + 1));
	if (s2 == NULL)
		return (NULL);
	else
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	of;
	char	*pointer;

	of = count * size;
	if (of != 0 && (of / size) != count && size > 0)
		return (NULL);
	pointer = malloc(of);
	if (pointer != NULL)
		ft_bzero(pointer, of);
	return (pointer);
}

void	ft_bzero( void *dst, size_t n)
{
	ft_memset(dst, 0, n);
}
