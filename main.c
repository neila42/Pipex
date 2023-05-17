#include "pipex.h"

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

int first_fork(t_list_fork *list, char **env)
{
	if (fork() == 0)
	{
		close(0);
		if (dup2(fd1, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
		{
			perror("error dup2");
			exit(1);
		}
		close(1);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		close(fd1);
		execve(list->path_name_cmd1, list->arg_cmd1, env);
		perror("error exec command");
		exit(1);
	}
}

int	create_fork(t_list_fork *list, char **argv, char **env)
{
	int	fd_pipe[2];
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	pipe(fd_pipe);
	if (fd1 == -1)
	{
		perror("open fd1");
		exit(1);
	}
	if (first_fork() == -1)
		exit(1);
	else
	{
		close(fd1);
		fd2 = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR
				| S_IRGRP | S_IROTH);
		if (fd2 == -1)
		{
			perror("open fd2");
			exit(1);
		}
		if (fork() == 0)
		{	
			close (1);
			if (dup2(fd2, 1) == -1 || dup2(fd_pipe[0], 0) == -1)
			{
				perror("error dup2");
				exit(1);
			}
			close(0);
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			close(fd2);
			if (execve(list->path_name_cmd2, list->arg_cmd2, env) == -1)
			{
				perror("error exec command");
				exit(1);
			}
		}
		else
		{
			printf("before wait\n");
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			while (wait(NULL) != -1)
			{
				if (errno != ECHILD)
					perror("waiting failed");
			}
		}
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

int	main(int argc, char **argv, char **env)
{	
	t_list_fork	list;

	list.arg_cmd1 = ft_split(argv[2], ' ');
	if (list.arg_cmd1 == NULL)
		printf("error arg_cmd1");
	list.arg_cmd2 = ft_split(argv[3], ' ');
	if (list.arg_cmd2 == NULL)
		printf("error arg_cmd2");
	list.prog_name1 = list.arg_cmd1[0];
	list.prog_name2 = list.arg_cmd2[0];
	list.path = get_path(env);
	if (list.path == NULL)
		printf("error path");
	list.path_split = ft_split(list.path, ':');
	if (list.path_split == NULL)
		printf("error path_split");
	list.path_name_cmd1 = get_path_name(list.path_split, list.prog_name1);
	if (list.path_name_cmd1 == NULL)
		printf("error path_name_cmd1");
	list.path_name_cmd2 = get_path_name(list.path_split, list.prog_name2);
	if (list.path_name_cmd2 == NULL)
		printf("error path_name_cmd2");
	create_fork(&list, &argv, &env);
	return (0);
}
