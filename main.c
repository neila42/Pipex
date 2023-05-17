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

int	main(int argc, char **argv)
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
	list.path = get_path(list.env);
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
	create_fork(&list, &argv);
	return (0);
}
