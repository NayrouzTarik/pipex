/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:00:43 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/31 15:31:53 by ntarik           ###   ########.fr       */
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


int         pipe_it(int *fd);
char        **is_cmd_composed(char *av);
int         is_executable_1(int ac, char *av, char **envp);
char        **find_path(char **env);
int         check_my_in_files(char **av);
int         check_my_out_files(int ac, char **av);
int         redirecting_infile(int fd_in);
int         redirecting_outfile(int fd_out);
char        **ft_split(const char *str, char c);
char        *ft_substr(const char *s, unsigned int start, size_t len);
char        *ft_strdup(const char *s1);
size_t      ft_strlen(const char *s);
void        *ft_calloc(size_t count, size_t size);
void        ft_bzero( void *dst, size_t n );
void        *ft_memset(void *ptr, int x, size_t n);
char        *ft_strjoin(char const *s1, char const *s2);

#endif