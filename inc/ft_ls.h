#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include "../Libft/inc/libft.h"

typedef struct s_data
{
	DIR				*folder;
	char			*path;
	int				is_aflag;
	int				is_lflag;
	int				is_tflag;
	int				is_rflag;
	int				is_Rflag;
	int				path_len;
	struct group	*grp;
	struct passwd	*pwd;
	struct dirent	*entry;
	struct stat		filestat;
}	t_data;

typedef struct s_file
{
	char		*name;
	long int	last_modified;
}	t_file;

void	parse(char **argv, t_data *data);
int		run(t_data *data);
void	print_files(char *path, t_data *data);
void	sort_files(char **arr, char *path, t_data *data, int n);

void	quick_sort_str(char **arr, int low, int high);
void	quick_sort_struct(t_file *struct_arr, int low, int high);
void	rverese_array(char *arr[], int start, int end);

#endif
