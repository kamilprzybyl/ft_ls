#include "ft_ls.h"

void initialize_var(t_info *info)
{
    info->is_aflag = 0;
    info->is_lflag = 0;
    info->is_tflag = 0;
    info->is_rflag = 0;
    info->is_Rflag = 0;
    info->i = 1;
}

int main(int argc, char **argv)
{
    t_info          info;

    initialize_var(&info);

    check_flag(argv, &info);

    info.path_len = strlen(argv[info.i]);
    info.folder = opendir(argv[info.i]);
    argc++;                                 /* only for silence warning about unused variable */
    
    if (info.is_aflag && info.is_lflag)
        la_flag(argv, &info);
    else if (info.is_lflag)
        l_flag(argv, &info);
    else if (info.is_aflag)
        a_flag(&info);
    else
        no_flag(&info);
    
    closedir(info.folder);

    return (0);
}