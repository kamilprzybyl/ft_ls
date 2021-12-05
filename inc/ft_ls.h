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
	int				is_aflag;
	int				is_lflag;
	int				is_tflag;
	int				is_rflag;
	int				is_Rflag;
	int				path_len;
	char			*path;
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
void	run(t_data *data);
void	print_files(char *path, t_data *data);
void	print_normal(char **arr);
void	print_long(char *path, t_data *data, char **arr);
void	run_recursively(t_data *data);
void	quick_sort_str(char **arr, int low, int high);
void	quick_sort_struct(t_file *struct_arr, int low, int high);
void	swap_str(char **a, char **b);
void	swap_struct(t_file *a, t_file *b);
void	rverese_array(char *arr[], int start, int end);
void	handle_tflag(char **arr, char *path, t_data *data, int n);

#endif
