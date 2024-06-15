/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:00:43 by ntarik            #+#    #+#             */
/*   Updated: 2024/06/14 23:10:22 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid;
	pid_t	pid2;
	int		status;
}		t_pipex;
//parse functions :
char	**find_path(char **env);
void	check_my_in_files(char **av);
void	check_my_out_files(int ac, char **av);
char	**is_cmd_composed(char *av);
int		check_args(int ac, char **av);
//errors functions : 
void	no_file_dire(char *str);
void	permission_error(char *str);
void	ft_error(char *str);
void	command_not_found(char *str);
//execute functions :
char	*is_executable(char *av, char **envp, char **path);
void	child_process(int *fd, char **av, char **env);
//helper functions :
char	**ft_split(const char *str, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero( void *dst, size_t n );
void	*ft_memset(void *ptr, int x, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int x, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero( void *dst, size_t n);
int		counter(const char *str, char c);
int		ft_strncmp( const char *p1, const char *p2, size_t n);
void	free2d(char **str);
//special case : of command sent with it path
int		with_path(char *av);
#endif