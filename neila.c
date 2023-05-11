#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include <fcntl.h>

char	*get_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return ((*env) + 5);
		env++;
	}
	return (NULL);
}

char	*get_path_name(char **path_split, char *prog_name)
{
	char	buff[255];

	if (access(prog_name, X_OK) == 0)
		return (prog_name);
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

int	create_fork(char **arg_cmd1, char **arg_cmd2, char *path_name_cmd1, char *path_name_cmd2, char **env, char **argv)
{
	int fd_pipe[2];
	pipe(fd_pipe);
	if (fork() == 0)
	{
		int fd1 = open(argv[1], O_RDONLY);
		close(0);
		dup2(fd1, 0);
		close(1);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		close(fd1);
		execve(path_name_cmd1, arg_cmd1, env);

	}
	else
	{
		if (fork() == 0)
		{
			int fd2 = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			close (1);
			dup2(fd2, 1);
			close(0);
			dup2(fd_pipe[0], 0);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			close(fd2);
			execve(path_name_cmd2, arg_cmd2, env);

		}
	}
	return (0);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while(split[i])
	{
		free(split[i])
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

int	main(int argc, char **argv, char **env)
{
	char **arg_cmd1 = ft_split(argv[2],' ');
	if (arg_cmd1 == NULL)
		printf("error arg_cmd1");
	char **arg_cmd2 = ft_split(argv[3], ' ');
	if (arg_cmd2 == NULL)
		ft_putstr_fd()
	char *prog_name1 = arg_cmd1[0];
	char *prog_name2 = arg_cmd2[0];
	char *path = get_path(env);
	if (path == NULL)
		printf("error path");
	char **path_split = ft_split(path, ':');
	if (*path_split == NULL)
		printf("error path_split");
	char *path_name_cmd1 = get_path_name(path_split, prog_name1);
	if (path_name_cmd1 == NULL)
		printf("error path_name_cmd1");
	char *path_name_cmd2 = get_path_name(path_split, prog_name2);
	if (path_name_cmd2 == NULL)
		printf("error path_name_cmd2");
	create_fork(arg_cmd1, arg_cmd2, path_name_cmd1, path_name_cmd2, env, argv);
	free(prog_name)
	return (0);
}
