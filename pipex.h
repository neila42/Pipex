/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/05/23 11:57:46 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "libft.h"

typedef struct s_list_fork {
	char	**arg_cmd1;
	char	**arg_cmd2;
	char	*prog_name1;
	char	*prog_name2;
	char	*path;
	char	**path_split;
	char	*path_name_cmd1;
	char	*path_name_cmd2;
	char	**env;
	int		fd1;
	int		fd2;
}			t_list_fork;

int		exec_fork(t_list_fork *list, char **argv);
void	free_all(t_list_fork list);
void	free_split(char **split);

#endif
