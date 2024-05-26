/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:00:43 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/25 19:20:13 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


char	**ft_split(const char *str, char c);
char **find_path(char **env);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero( void *dst, size_t n );
void	*ft_memset(void *ptr, int x, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
#endif