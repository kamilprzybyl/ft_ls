#include "ft_ls.h"


void check_flag(char **argv, t_info *info)
{
    while (argv[info->i])
    {
        if (strcmp(argv[info->i], "-a") == 0)
            info->is_aflag = 1;
        else if (strcmp(argv[info->i], "-l") == 0)
            info->is_lflag = 1;
        else if (strcmp(argv[info->i], "-t") == 0)
            info->is_tflag = 1;
        else if (strcmp(argv[info->i], "-r") == 0)
            info->is_rflag = 1;
        else if (strcmp(argv[info->i], "-R") == 0)
            info->is_Rflag = 1;
        else
            break;

        info->i++;
    }    
}