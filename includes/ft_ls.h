#include <stdio.h>
#include <dirent.h>     /* opendir, readdir, closedir functions */
#include <string.h>
#include <sys/stat.h>   /* stat function */
#include <time.h>       /* ctime function */
#include <pwd.h>        /* getpwuid funtion */
#include <grp.h>        /* getgrgid function */
#include <stdlib.h>     /* malloc function */

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


void check_flag(char **argv, t_info *info);
void print_long(char *path, t_info *info);
void handle_input(char *path, t_info *info);
void print_files(char *path, t_info *info);
void handle_recursion(char *path, t_info *info);