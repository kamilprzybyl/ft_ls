#include "ft_ls.h"


void la_flag(char **argv, t_info *info)
{
    while ((info->entry = readdir(info->folder)))
    {
        info->path = strcat(argv[info->i], info->entry->d_name);
        stat(info->path, &info->filestat);
        info->pwd = getpwuid(info->filestat.st_uid);
        info->grp = getgrgid(info->filestat.st_gid);

        printf( (S_ISDIR(info->filestat.st_mode)) ? "d" : "-");
        printf( (info->filestat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (info->filestat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (info->filestat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (info->filestat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (info->filestat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (info->filestat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (info->filestat.st_mode & S_IROTH) ? "r" : "-");
        printf( (info->filestat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (info->filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
        printf("%2d", info->filestat.st_nlink);
        printf("%13s", info->pwd->pw_name);
        printf("%7s", info->grp->gr_name);
        printf("%7lld", info->filestat.st_size);
        // printf("%s", ctime(&info->filestat->st_mtime));
        printf(" %s", info->entry->d_name);
        printf("\n");
        bzero(&(info->path[info->path_len]), strlen(info->path));
    }    
}


void l_flag(char **argv, t_info *info)
{
    while ((info->entry = readdir(info->folder)))
    {
        info->path = strcat(argv[info->i], info->entry->d_name);
        stat(info->path, &info->filestat);
        info->pwd = getpwuid(info->filestat.st_uid);
        info->grp = getgrgid(info->filestat.st_gid);
        if (info->entry->d_name[0] != '.')
        {
            printf( (S_ISDIR(info->filestat.st_mode)) ? "d" : "-");
            printf( (info->filestat.st_mode & S_IRUSR) ? "r" : "-");
            printf( (info->filestat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (info->filestat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (info->filestat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (info->filestat.st_mode & S_IWGRP) ? "w" : "-");
            printf( (info->filestat.st_mode & S_IXGRP) ? "x" : "-");
            printf( (info->filestat.st_mode & S_IROTH) ? "r" : "-");
            printf( (info->filestat.st_mode & S_IWOTH) ? "w" : "-");
            printf( (info->filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
            printf("%2d  ", info->filestat.st_nlink);
            printf("%13s", info->pwd->pw_name); 
            printf("%7s", info->grp->gr_name);
            printf("%7lld", info->filestat.st_size);
            // printf("%s", ctime(&info->filestat->st_mtime));
            printf(" %s", info->entry->d_name);
            printf("\n");
        }
        bzero(&(info->path[info->path_len]), strlen(info->path));
    }    
}


void a_flag(t_info *info)
{
    while ((info->entry = readdir(info->folder)))
        printf("%-12s", info->entry->d_name);

    printf("\n");    
}


void no_flag(t_info *info)
{
    while ((info->entry = readdir(info->folder)))
        if (info->entry->d_name[0] != '.')
            printf("%-12s", info->entry->d_name);

    printf("\n");    
}