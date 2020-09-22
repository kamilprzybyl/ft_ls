#include "ft_ls.h"


void handle_input(char *path, t_info *info)
{
    print_files(path, info);

    if (info->is_Rflag)
    {
        printf("\n");
        handle_recursion(path, info);
    }
}

void handle_recursion(char *path, t_info *info)
{
    DIR             *folder;
    int             path_len;

    path_len = strlen(path);
    folder = opendir(path);

    while ((info->entry = readdir(folder)))
    { 
        path = strcat(path, "/");
        path = strcat(path, info->entry->d_name);
        stat(path, &info->filestat);
        if (S_ISDIR(info->filestat.st_mode))
        {
            if ((info->entry->d_name[0] != '.' || info->is_aflag) && (strcmp(".", info->entry->d_name) && strcmp("..", info->entry->d_name)))
            {
                printf("%s:\n", path);
                handle_input(path, info);
            }
        }
        bzero(&(path[path_len]), strlen(path));
    }
    closedir(folder);
}


void print_long(char *path, t_info *info, char **arr)
{
    char            *modify_date;
    char            *new_str;      
    int             path_len;
    int             i;

    i = 0;
    while (arr[i])
    {
        path_len = strlen(path);
        path = strcat(path, "/");
        path = strcat(path, arr[i]);
        stat(path, &info->filestat);
        info->pwd = getpwuid(info->filestat.st_uid);
        info->grp = getgrgid(info->filestat.st_gid);

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
        new_str = malloc(13 * sizeof(char));
        new_str = strncpy(new_str, &(modify_date[4]), 12);
        new_str[12] = '\0';
        printf(" %s", new_str);           
        printf(" %s", arr[i]);
        printf("\n");

        bzero(&(path[path_len]), strlen(path));
        i++;
    }
}

void print_normal(char **arr) 
{ 
    int     i;
    
    i = 0;
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
} 


void print_files(char *path, t_info *info)
{
    DIR     *folder;
    char    **arr;
    int     len_arr;
    int     n;

    folder = opendir(path);
    len_arr = 0;
    arr = malloc((len_arr + 1) * sizeof(char *));
    arr[len_arr] = NULL;

    while ((info->entry = readdir(folder)))
    {
        if (info->entry->d_name[0] != '.' || info->is_aflag)
        {
            arr = realloc(arr, (len_arr + 1 + 1) * sizeof(*arr));
            arr[len_arr] = malloc(254 * sizeof(char));
            strcpy(arr[len_arr], info->entry->d_name);
            len_arr++;
            arr[len_arr] = NULL;
        }
    }

    n = 0;
    while (arr[n])
        n++;
    quick_sort(arr, 0, n-1);

    if (info->is_rflag)
        rverese_array(arr, 0, n-1);

    if (info->is_lflag)
        print_long(path, info, arr);
    else
        print_normal(arr);

    closedir(folder);
}