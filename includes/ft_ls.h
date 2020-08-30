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
    DIR             *temp_folder;

    int             is_aflag;
    int             is_lflag;
    int             is_tflag;
    int             is_rflag;
    int             is_Rflag;

    int             path_len;
    char            *path;
    struct stat     filestat;
    struct dirent   *entry;
    int             i;
    struct passwd   *pwd;
    struct group    *grp;

}                   t_info;


void check_flag(char **argv, t_info *info);
void la_flag(char **argv, t_info *info);
void l_flag(char **argv, t_info *info);
void a_flag(char **argv, t_info *info);
void R_flag(char *path);
void no_flag(char **argv, t_info *info);