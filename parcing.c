/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:06:53 by ntarik            #+#    #+#             */
/*   Updated: 2024/05/26 20:25:13 by ntarik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **find_path(char **env)
{
    int i = 0;
    while (env[i])
    {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
            return (ft_split(env[i] + 5, ':'));
        i++;
    }
    return (NULL);

}

int check_file(char **av)
{
    if (access(av[1], F_OK) == -1 )
    {
        printf("Error 1 : file does not exist\n");
        return (0);
    }
    if (access(av[4], F_OK) == -1)
    {
        open(av[4], O_CREAT | O_RDWR, 0777);
    }
    if (access(av[1], X_OK) == -1)
    {
        printf("File is not executable 2 \n");
        return (0);
    }
    if (access(av[1], R_OK) == -1 || access(av[4], R_OK) == -1)
    {
        printf("File  is not readable 3 \n");
        return (0);
    }
    if (access(av[4], W_OK) == -1)
    {
        printf("File is not writable 4 \n");
        return (0);
    }
    return (1);
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

int is_executable_1(int ac, char **av, char **envp)
{
    (void)ac;
    int i ;
    char **res;

    i = 0;
    res = find_path(envp);
    while (res[i])
    {
        char *cmd_name = av[2]; 
        char **cmd = is_cmd_composed(av[2]);
        char *cmd_path = res[i];
        char *final = ft_strjoin(cmd_path, "/");
        char *final_final = ft_strjoin(final, cmd[0]);
        printf("%s\n", final_final);
        if (access(final_final, X_OK) != -1)
        {
            printf("{%s}\n", final_final);
            if (execve(final_final, cmd, envp) == -1)
                printf("Attempting to execute {%s}: %s\n", cmd_name, res[i]);
            printf("Error: command not found\n");
        }
        i++;
    }
    return 0;
}


int parse_all(int ac, char **av, char **env)
{
    if (ac != 5)
    {
        printf("Error: wrong number of arguments\n");
        return (0); 
    }
    if ((check_file(av) == 0))
    {
        perror("Error: command not found\n");
        exit(1);
    }
    if ( (is_executable_1(ac, av, env) == 0))
    {
        perror("Error: command not found\n");
        exit(1);
    }
    if (is_executable_2(ac, av, env) == 0)
    {
        perror("Error: command not found\n");
        exit(1);
    }
    return (1);
}

int main(int ac, char **av, char **envp)
{
    (void)ac;
    int bla = parse_all(ac, av, envp);
    printf("%d\n", bla);
}
