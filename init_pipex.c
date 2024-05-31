/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:30:06 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/31 15:30:14 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int pipe_it(int *fd)
{
    if (pipe(fd) == -1)
    {
        write(2, "Pipe failed\n", 12);
        exit(1);
    }
    return (*fd);
}

char **is_cmd_composed(char *av)
{
    char **cmd;
    cmd = (char **)malloc(2 * sizeof(char *));
    if(cmd == NULL)
        return NULL;
    if(strchr(av, ' ') != NULL)
    {
        cmd = ft_split(av, ' ');
        return cmd;
    }
    cmd[0] = av;
    cmd[1] = NULL;
    return cmd;
}

int is_executable_1(int ac, char *av, char **envp)
{
    (void)ac;
    int i ;
    char **res;

    i = 0;
    res = find_path(envp);
    while (res[i])
    {
        char **cmd = is_cmd_composed(av);
        char *cmd_path = res[i];
        char *final = ft_strjoin(cmd_path, "/");
        char *final_final = ft_strjoin(final, cmd[0]);
        printf("%s\n", final_final);
        if (access(final_final, X_OK) != -1)
        {
            printf("{%s}\n", final_final);
            // if (execve(final_final, cmd, envp) == -1)
            execve(final_final, cmd, envp);
                // printf("Attempting to execute {%s}: %s\n", av, res[i]);
            // printf("Error: command not found\n");
        }
        i++;
    }
    return 0; 
}

int main (int ac, char **av, char **env)
{
    int a = check_my_in_files(av);
    int b = check_my_out_files(ac, av);
    int fd[2];
    int status;
    pipe_it(fd);
    // printf("bef fd[0] = %d\n", fd[0]);
    // printf("fbef d[1] = %d\n", fd[1]);
    pid_t pid = fork();
    if (pid > 0)
    {
        dup2(b, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        waitpid(-1, &status, 0);
        is_executable_1(fd[0], av[3], env);
    }
    else if (pid == 0)
    {   
        dup2(a, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        is_executable_1(fd[1], av[2], env);
    }
    exit(1);
}