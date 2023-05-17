#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/errno.h>

typedef struct s_list_fork {
    char    **arg_cmd1;
    char    **arg_cmd2;
    char	*prog_name1;
	char	*prog_name2;
    char	*path;
    char	**path_split;
    char    *path_name_cmd1;
    char    *path_name_cmd2;
    int	    fd_pipe[2];
	int 	fd1;
	int	    fd2;

}t_list_fork;

char	*get_path(char **env);
char	*get_path_name(char **path_split, char *prog_name);
int     create_fork(t_list_fork *list, char **argv, char **env);
void	free_split(char **split);
int     main(int argc, char **argv, char **env);

#endif