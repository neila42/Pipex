/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/05/23 12:20:33 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_fork(t_list_fork *list, int fd1, int fd2, int *fd_pipe)
{
	if (fork() == 0)
	{
		close(fd2);
		close(1);
		close(0);
		if (dup2(fd1, 0) == -1 || dup2(fd_pipe[1], 1) == -1)
		{
			perror("error dup2");
			exit(1);
		}
		close(fd_pipe[1]);
		close(fd_pipe[0]);
		close(fd1);
		execve(list->path_name_cmd1, list->arg_cmd1, list->env);
		perror("error exec command");
		exit(1);
	}
	return (0);
}

static int	open_fd(char **argv, int *fd2)
{
	*fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IROTH);
	if (*fd2 == -1)
	{
		perror("open outfile");
		exit(1);
	}
	return (0);
}

static int	seconde_fork(t_list_fork *list, int fd1, int fd2, int *fd_pipe)
{
	if (fork() == 0)
	{	
		close(fd1);
		close (1);
		close (0);
		if (dup2(fd2, 1) == -1 || dup2(fd_pipe[0], 0) == -1)
		{
			perror("error dup2");
			exit(1);
		}
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		close(fd2);
		if (execve(list->path_name_cmd2, list->arg_cmd2, list->env) == -1)
		{
			perror("error exec command");
			exit(1);
		}
	}
	return (0);
}

int	exec_fork(t_list_fork *list, char **argv)
{
	int	fd_pipe[2];
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("open infile");
		exit(1);
	}
	open_fd(argv, &fd2);
	pipe(fd_pipe);
	if (first_fork(list, fd1, fd2, (int *)&fd_pipe)
		|| seconde_fork(list, fd1, fd2, (int *)&fd_pipe))
		exit(1);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd2);
	close(fd1);
	while (wait(NULL) != -1)
		continue ;
	if (errno != ECHILD)
		perror("waiting failed");
	return (0);
}

void	free_all(t_list_fork list)
{
	free_split(list.arg_cmd1);
	free_split(list.arg_cmd2);
	free_split(list.path_split);
	free(list.path_name_cmd1);
	free(list.path_name_cmd2);
}
