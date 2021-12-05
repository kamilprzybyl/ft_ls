#include "../inc/ft_ls.h"

static char	**create_arr(char *path, t_data *data)
{
	DIR		*folder;
	char	**arr;
	int		arr_len;

	folder = opendir(path);
	arr_len = 0;
	arr = malloc((arr_len + 1) * sizeof(char *));
	arr[arr_len] = NULL;
	while ((data->entry = readdir(folder)))
	{
		if (data->entry->d_name[0] != '.' || data->is_aflag)
		{
			arr = realloc(arr, (arr_len + 1 + 1) * sizeof(*arr));
			arr[arr_len] = malloc(254 * sizeof(char));
			ft_strlcpy(arr[arr_len], data->entry->d_name, ft_strlen(data->entry->d_name) + 1);
			arr_len++;
			arr[arr_len] = NULL;
		}
	}
	closedir(folder);
	return (arr);
}

static void	print_long(char *path, t_data *data, char **arr)
{
	char	*modify_date;
	char	*new_str;
	int		path_len;
	int		i;

	i = 0;
	while (arr[i])
	{
		path_len = ft_strlen(path);
		path = strcat(path, "/");
		path = strcat(path, arr[i]);
		stat(path, &data->filestat);
		data->pwd = getpwuid(data->filestat.st_uid);
		data->grp = getgrgid(data->filestat.st_gid);
		printf( (S_ISDIR(data->filestat.st_mode)) ? "d" : "-");
		printf( (data->filestat.st_mode & S_IRUSR) ? "r" : "-");
		printf( (data->filestat.st_mode & S_IWUSR) ? "w" : "-");
		printf( (data->filestat.st_mode & S_IXUSR) ? "x" : "-");
		printf( (data->filestat.st_mode & S_IRGRP) ? "r" : "-");
		printf( (data->filestat.st_mode & S_IWGRP) ? "w" : "-");
		printf( (data->filestat.st_mode & S_IXGRP) ? "x" : "-");
		printf( (data->filestat.st_mode & S_IROTH) ? "r" : "-");
		printf( (data->filestat.st_mode & S_IWOTH) ? "w" : "-");
		printf( (data->filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
		printf("%2d  ", data->filestat.st_nlink);
		printf("%13s", data->pwd->pw_name); 
		printf("%7s", data->grp->gr_name);
		printf("%7lld", data->filestat.st_size);
		modify_date = ctime(&data->filestat.st_mtime);
		new_str = malloc(13 * sizeof(char));
		new_str = strncpy(new_str, &(modify_date[4]), 12);
		new_str[12] = '\0';
		printf(" %s", new_str);
		free(new_str);
		printf(" %s", arr[i]);
		printf("\n");
		ft_bzero(&(path[path_len]), ft_strlen(path));
		i++;
	}
}

static void	print_normal(char **arr) 
{
	int     i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);  
		i++;
	}
}

void	print_files(char *path, t_data *data)
{
	char	**arr;
	int		arr_len;
	int		i;

	arr = create_arr(path, data);
	arr_len = 0;
	i = 0;
	while (arr[arr_len])
		arr_len++;
	quick_sort_str(arr, 0, arr_len-1);
	if (data->is_tflag)
		sort_files(arr, path, data, arr_len);
	if (data->is_rflag)
		rverese_array(arr, 0, arr_len-1);
	if (data->is_lflag)
		print_long(path, data, arr);
	else
		print_normal(arr);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}
