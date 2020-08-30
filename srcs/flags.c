#include "ft_ls.h"


void R_flag(char *path)
{
    t_info      info;
    
    info.path_len = strlen(path);
    info.folder = opendir(path);
        
    while ((info.entry = readdir(info.folder)))
        if (info.entry->d_name[0] != '.')
            printf("%s  ", info.entry->d_name); 

    printf("\n\n");

    closedir(info.folder);
    info.folder = opendir(path);
    while ((info.entry = readdir(info.folder)))
    {
        path = strcat(path, "/");
        path = strcat(path, info.entry->d_name);
        stat(path, &info.filestat);
        if (S_ISDIR(info.filestat.st_mode)) // checking if it's folder
        {
            if (info.entry->d_name[0] != '.')
            {
                printf("%s:\n", path);
                R_flag(path);
            }
        }
        bzero(&(path[info.path_len]), strlen(path));
    }
    closedir(info.folder);
}


void la_flag(char **argv, t_info *info)
{
    char        *modify_date;
    char        *new_str;

    info->path_len = strlen(argv[info->i]);
    info->folder = opendir(argv[info->i]);

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
        modify_date = ctime(&info->filestat.st_mtime);
        new_str = malloc(12 * sizeof(char));
        new_str = strncpy(new_str, &(modify_date[4]), 12);
        printf(" %s", new_str);
        printf(" %s", info->entry->d_name);
        printf("\n");
        bzero(&(info->path[info->path_len]), strlen(info->path));
    }    
}


void l_flag(char **argv, t_info *info)
{
    char        *modify_date;
    char        *new_str;

    info->path_len = strlen(argv[info->i]);
    info->folder = opendir(argv[info->i]);

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
            modify_date = ctime(&info->filestat.st_mtime);
            new_str = malloc(12 * sizeof(char));
            new_str = strncpy(new_str, &(modify_date[4]), 12);
            printf(" %s", new_str);           
            printf(" %s", info->entry->d_name);
            printf("\n");
        }
        bzero(&(info->path[info->path_len]), strlen(info->path));
    }    
}


void a_flag(char **argv, t_info *info)
{
    info->path_len = strlen(argv[info->i]);
    info->folder = opendir(argv[info->i]);

    while ((info->entry = readdir(info->folder)))
        printf("%-12s", info->entry->d_name);

    printf("\n");    
}


void no_flag(char **argv, t_info *info)
{
    info->path_len = strlen(argv[info->i]);
    info->folder = opendir(argv[info->i]);

    while ((info->entry = readdir(info->folder)))
        if (info->entry->d_name[0] != '.')
            printf("%-12s", info->entry->d_name);

    printf("\n");    
}