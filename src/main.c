#include "../inc/ft_ls.h"

static void	init(t_data *data)
{
	data->is_aflag = 0;
	data->is_lflag = 0;
	data->is_tflag = 0;
	data->is_rflag = 0;
	data->is_Rflag = 0;
	data->is_rflag = 0;
}

int main(__attribute__ ((unused)) int argc, char **argv)
{
	t_data	data;

	init(&data);
	parse(argv, &data);
	if (run(&data) == 1);
		return (1);
	return (0);
}
