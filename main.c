//
// Created by Neila Muminovic on 5/4/23.
//
#include <unistd.h>
#include <stdio.h>
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

char *get_path_name(char **split_path, char *prog_name)
{
	char buff[255];

	while (*split_path)
	{
		ft_bzero(buff, sizeof(char) * 255);
		ft_strlcat(buff, *split_path, 255);
		ft_strlcat(buff, "/", 255);
		ft_strlcat(buff, prog_name, 255);
		if (access(buff, X_OK) == 0)
			return (ft_strdup(buff));
		split_path++;
	}
	return (NULL);
}

int	create_fork(char *path_name, char **env)
{
	char *tab[2] = {path_name, NULL};

	if (fork() == 0)
	{
		execve(path_name, tab, env);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	char *path;
	path = get_path(env);
	char **split_path = ft_split(path, ':');
	char *path_name = get_path_name(split_path, argv[1]);
	create_fork(path_name, env);
	return (0);
}