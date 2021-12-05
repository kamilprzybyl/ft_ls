#include "../inc/ft_ls.h"

void	run(t_data *data)
{
	print_files(data->path, data);
	if (data->is_Rflag)
	{
		printf("\n");
		run_recursively(data);
	}
}

void run_recursively(t_data *data)
{
    DIR             *folder;
    int             path_len;

    path_len = ft_strlen(data->path);
    folder = opendir(data->path);

    while ((data->entry = readdir(folder)))
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
    closedir(folder);
}
