#include "ft_ls.h"

void initialize_var(t_info *info)
{
    info->is_aflag = 0;
    info->is_lflag = 0;
    info->is_tflag = 0;
    info->is_rflag = 0;
    info->is_Rflag = 0;
    info->is_rflag = 0;
    info->i = 1;
}

int main(int __attribute__ ((unused)) argc, char **argv)
{
    t_info          info;

    initialize_var(&info);
    
    ls_check_flag(argv, &info);

    handle_input(argv[info.i], &info);

    return (0);
}