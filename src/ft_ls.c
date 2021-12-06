#include "../inc/ft_ls.h"

static void	run_recursively(t_data *data)
{
	int	path_len;

	path_len = ft_strlen(data->path);
	while ((data->entry = readdir(data->folder)))
	{ 
		data->path = strcat(data->path, "/");
		data->path = strcat(data->path, data->entry->d_name);
		stat(data->path, &data->filestat);
		if (S_ISDIR(data->filestat.st_mode))
		{
			if ((data->entry->d_name[0] != '.' || data->is_aflag) && (strcmp(".", data->entry->d_name) && strcmp("..", data->entry->d_name)))
			{
				printf("%s:\n", data->path);
				run(data);
			}
		}
		ft_bzero(&(data->path[path_len]), ft_strlen(data->path));
	}
	closedir(data->folder);
}

static int open_dir(t_data *data)
{
	data->folder = opendir(data->path);
	if (!data->folder)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(data->path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	run(t_data *data)
{
	if (open_dir(data) == 1)
		return (1);
	print_files(data->path, data);
	if (data->is_Rflag)
	{
		printf("\n");
		run_recursively(data);
	}
	return (0);
}
