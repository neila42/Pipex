#include "pipex.h"

int	first_fork(t_list_fork *list, int fd1, int fd2, int fd_pipe[2])
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
		execve(list->path_name_cmd1, list->arg_cmd1, list->env);
		perror("error exec command");
		exit(1);
	}
}

int	open_fd(char **argv, int fd1, int fd2)
{
	close(fd1);
		fd2 = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IROTH);
	if (fd2 == -1)
	{
		perror("open fd2");
		exit(1);
	}
}

int	seconde_fork(t_list_fork *list, int fd2, int fd_pipe[2])
{
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
		if (execve(list->path_name_cmd2, list->arg_cmd2, list->env) == -1)
		{
			perror("error exec command");
			exit(1);
		}
	}
}

int	exec_fork(t_list_fork *list, char **argv)
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
	if (first_fork(list, fd1, fd2, fd_pipe[2]) == -1)
		exit(1);
	else if (seconde_fork(list, fd2, fd_pipe[2]))
		exit(1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	while (wait(NULL) != -1)
	{
		if (errno != ECHILD)
			perror("waiting failed");
	}
}
