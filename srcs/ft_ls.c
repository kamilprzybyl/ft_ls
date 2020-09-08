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

    argc++;                                     /* only for silence warning about unused variable */

    if (info.is_aflag && info.is_lflag)
        la_flag(argv[info.i], &info);
    else if (info.is_aflag && info.is_Rflag)
        Ra_flag(argv[info.i]);
    else if (info.is_lflag && info.is_Rflag)
        Rl_flag(argv[info.i]);
    else if (info.is_lflag)
        l_flag(argv[info.i], &info);
    else if (info.is_aflag)
        a_flag(argv[info.i], &info);
    else if (info.is_Rflag)
        R_flag(argv[info.i]);
    else
        no_flag(argv[info.i], &info);

    return (0);
}