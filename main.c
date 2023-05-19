/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuminov <nmuminov@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:10:31 by nmuminov          #+#    #+#             */
/*   Updated: 2023/05/19 18:07:00 by nmuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return ((*env) + 5);
		env++;
	}
	return (NULL);
}

static char	*get_path_name(char **path_split, char *prog_name)
{
	char	buff[255];

	if (access(prog_name, X_OK) == 0)
		return (ft_strdup(prog_name));
	while (*path_split)
	{
		ft_bzero(buff, sizeof(char) * 255);
		ft_strlcat(buff, *path_split, 255);
		ft_strlcat(buff, "/", 255);
		ft_strlcat(buff, prog_name, 255);
		printf("pathname =>%s\n", buff);
		if (access(buff, X_OK) == 0)
			return (ft_strdup(buff));
		path_split++;
	}
	return (NULL);
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

static void	fail(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{	
	t_list_fork	list;

	if (argc <= 4)
		fail("error arg\n");
	list.env = env;
	list.arg_cmd1 = ft_split(argv[2], ' ');
	list.arg_cmd2 = ft_split(argv[3], ' ');
	if (list.arg_cmd1 == NULL || list.arg_cmd2 == NULL)
		fail("error arg_cmd\n");
	list.prog_name1 = list.arg_cmd1[0];
	list.prog_name2 = list.arg_cmd2[0];
	list.path = get_path(list.env);
	if (list.path == NULL)
		fail("error path\n");
	list.path_split = ft_split(list.path, ':');
	if (list.path_split == NULL)
		fail("error path_spli\n");
	list.path_name_cmd1 = get_path_name(list.path_split, list.prog_name1);
	list.path_name_cmd2 = get_path_name(list.path_split, list.prog_name2);
	if (list.path_name_cmd1 == NULL || list.path_name_cmd2 == NULL)
		fail("error path_name_cmd\n");
	exec_fork(&list, argv);
	free_all(list);
	return (0);
}
