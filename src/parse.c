#include "../inc/ft_ls.h"

static void	set_flag(t_data *data, char **argv, int i, int j)
{
	if (argv[i][j] == 'a') 
		data->is_aflag = 1;
	else if (argv[i][j] == 'l')
		data->is_lflag = 1;
	else if (argv[i][j] == 't')
		data->is_tflag = 1;
	else if (argv[i][j] == 'r')
		data->is_rflag = 1;
	else if (argv[i][j] == 'R')
		data->is_Rflag = 1;
}

void	parse(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][j])
			{
				set_flag(data, argv, i, j);
				j++;
			}
			i++;
		}
		else
			break;
	}
	if (argv[i])
		data->path = argv[i];
	else
		data->path = ft_strdup(".");
}
