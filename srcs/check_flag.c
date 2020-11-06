#include "ft_ls.h"


void ls_check_flag(char **argv, t_info *info)
{
    int     x;

    while (argv[info->i])
    {
        if (argv[info->i][0] == '-')
        {
            x = 0;
            while (argv[info->i][x])
            {
                if (argv[info->i][x] == 'a') 
                    info->is_aflag = 1;
                else if (argv[info->i][x] == 'l')
                    info->is_lflag = 1;
                else if (argv[info->i][x] == 't')
                    info->is_tflag = 1;
                else if (argv[info->i][x] == 'r')
                    info->is_rflag = 1;
                else if (argv[info->i][x] == 'R')
                    info->is_Rflag = 1;
                
                x++;
            }
            info->i++;
        }
        else
            break;
    }    
}