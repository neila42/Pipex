#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char *get_path(char **env)
{
    while (*env)
    {
        if (ft_strncmp(*env, "PATH=", 5) == 0)
            return ((*env) + 5);
        env++;
    }
    return (NULL);
}

char *get_path_name(char **path_split, char *prog_name)
{
    char buff[255];

    while (*path_split)
    {
        ft_bzero(buff, sizeof(char) * 255);
        ft_strlcat(buff, *path_split, 255);
        ft_strlcat(buff, "/", 255);
        ft_strlcat(buff, prog_name, 255);
        printf("pathname =>%s\n", buff);
        if (access(buff, X_OK) == 0)
            return (strdup(buff));
        path_split++;
    }
    return (NULL);
}

int create_fork(char **arg_cmd1, char **arg_cmd2, char *path_name_cmd1, char *path_name_cmd2, char **env)
{
    if (fork() == 0)
    {
        execve (path_name_cmd1, arg_cmd1, env);
    }
    else
    {
        execve (path_name_cmd2, arg_cmd2, env);
    }
    return (0);
}

int main(int argc, char **argv, char **env)
{
    char **arg_cmd1 = ft_split(argv[1],' ');
    if (arg_cmd1 == NULL)
        printf("error arg_cmd1");
    char **arg_cmd2 = ft_split(argv[2], ' ');
    if (arg_cmd2 == NULL)
        printf("error arg_cmd2");
    char *prog_name = arg_cmd1[0];
    char *path = get_path(env);
    if (path == NULL)
        printf("error path");
    char **path_split = ft_split(path, ':');
    if (*path_split == NULL)
        printf("error path_split");
    char *path_name_cmd1 = get_path_name(path_split, prog_name_cmd1);
    if (path_name_cmd1 == NULL)
        printf("error path_name_cmd1");
    char *path_name_cmd2 = get_path_name(path_split, prog_name_cmd2);
    if (path_name_cmd2 == NULL)
        printf("error path_name_cmd2");
    create_fork(arg_cmd1, arg_cmd2, path_name_cmd1, path_name_cmd2, env);
    return (0);
}


