#include <stdio.h>
#include <dirent.h>                         /* opendir, readdir, closedir functions */
#include <string.h>     
#include <sys/stat.h>                       /* stat function */
#include <time.h>                           /* ctime function */
#include <pwd.h>                            /* getpwuid funtion */
#include <grp.h>                            /* getgrgid function */
#include <stdlib.h>                         /* malloc function */
#include "../Libft/includes/libft.h"

typedef struct      s_info
{
    DIR             *folder;

    int             is_aflag;
    int             is_lflag;
    int             is_tflag;
    int             is_rflag;
    int             is_Rflag;

    int             i;
    struct group    *grp;
    struct passwd   *pwd;
    struct dirent   *entry;
    struct stat     filestat;
    int             path_len;
    char            *path;

}                   t_info;

typedef struct      s_file
{
    char            *name;
    long int        last_modified;      

}                   t_file;                


void ls_check_flag(char **argv, t_info *info);
void handle_input(char *path, t_info *info);
void print_files(char *path, t_info *info);
void print_normal(char **arr);
void print_long(char *path, t_info *info, char **arr);
void handle_recursion(char *path, t_info *info);
void quick_sort_str(char **arr, int low, int high);
void quick_sort_struct(t_file *struct_arr, int low, int high);
void swap_str(char **a, char **b);  
void swap_struct(t_file *a, t_file *b);
void rverese_array(char *arr[], int start, int end);
void handle_tflag(char **arr, char *path, t_info *info, int n);
char **create_arr(char *path, t_info *info);