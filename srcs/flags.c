#include "ft_ls.h"


void handle_input(char *path, t_info *info)
{
    print_files(path, info);

    if (info->is_Rflag)
    {
        ft_printf("\n");
        handle_recursion(path, info);
    }
}

void print_files(char *path, t_info *info)
{
    char    **arr;
    int     arr_len;
    int     i;

    arr = create_arr(path, info);
    arr_len = 0;
    i = 0;

    while (arr[arr_len])
        arr_len++;

    quick_sort_str(arr, 0, arr_len-1);

    if (info->is_tflag)
        handle_tflag(arr, path, info, arr_len);
    if (info->is_rflag)
        rverese_array(arr, 0, arr_len-1);

    if (info->is_lflag)
        print_long(path, info, arr);
    else
        print_normal(arr);

    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
}

char **create_arr(char *path, t_info *info)
{
    DIR     *folder;
    char    **arr;
    int     arr_len;

    folder = opendir(path);
    arr_len = 0;
    arr = malloc((arr_len + 1) * sizeof(char *));
    arr[arr_len] = NULL;

    while ((info->entry = readdir(folder)))
    {
        if (info->entry->d_name[0] != '.' || info->is_aflag)
        {
            arr = realloc(arr, (arr_len + 1 + 1) * sizeof(*arr));
            arr[arr_len] = malloc(254 * sizeof(char));
            ft_strcpy(arr[arr_len], info->entry->d_name);
            arr_len++;
            arr[arr_len] = NULL;
        }
    }

    closedir(folder);

    return (arr);
}

void handle_tflag(char **arr, char *path, t_info *info, int arr_len)
{
    int             path_len;
    int             i;
    t_file          tfile[arr_len];

    i = 0;
    /* In the loop below we have to create a struct which will keep a file name and its last modified time */
    while (arr[i])
    {
        path_len = ft_strlen(path);
        path = ft_strcat(path, "/");
        path = ft_strcat(path, arr[i]);
        stat(path, &info->filestat);

        tfile[i].name = malloc(254 * sizeof(char));
        ft_strcpy(tfile[i].name, arr[i]);
        tfile[i].last_modified = info->filestat.st_mtime;
        ft_bzero(&(path[path_len]), ft_strlen(path));
        i++;
    }        
    quick_sort_struct(tfile, 0, arr_len-1);

    i = 0;
    /* now from already sorted struct array we have to copy file names to an arr because we don't want to keep it in a structure (because our print functions do not read from structure but from array of strings)*/
    while (arr[i])
    {
        ft_bzero(arr[i], ft_strlen(arr[i]));
        ft_strcpy(arr[i], tfile[i].name);
        free(tfile[i].name);
        i++;
    }
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
        path_len = ft_strlen(path);
        path = ft_strcat(path, "/");
        path = ft_strcat(path, arr[i]);
        stat(path, &info->filestat);
        info->pwd = getpwuid(info->filestat.st_uid);
        info->grp = getgrgid(info->filestat.st_gid);

        ft_printf( (S_ISDIR(info->filestat.st_mode)) ? "d" : "-");
        ft_printf( (info->filestat.st_mode & S_IRUSR) ? "r" : "-");
        ft_printf( (info->filestat.st_mode & S_IWUSR) ? "w" : "-");
        ft_printf( (info->filestat.st_mode & S_IXUSR) ? "x" : "-");
        ft_printf( (info->filestat.st_mode & S_IRGRP) ? "r" : "-");
        ft_printf( (info->filestat.st_mode & S_IWGRP) ? "w" : "-");
        ft_printf( (info->filestat.st_mode & S_IXGRP) ? "x" : "-");
        ft_printf( (info->filestat.st_mode & S_IROTH) ? "r" : "-");
        ft_printf( (info->filestat.st_mode & S_IWOTH) ? "w" : "-");
        ft_printf( (info->filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
        ft_printf("%2d  ", info->filestat.st_nlink);
        ft_printf("%13s", info->pwd->pw_name); 
        ft_printf("%7s", info->grp->gr_name);
        ft_printf("%7lld", info->filestat.st_size);
        modify_date = ctime(&info->filestat.st_mtime);
        new_str = malloc(13 * sizeof(char));
        new_str = ft_strncpy(new_str, &(modify_date[4]), 12);
        new_str[12] = '\0';
        ft_printf(" %s", new_str);         
        free(new_str);
        ft_printf(" %s", arr[i]);          
        ft_printf("\n");                     

        ft_bzero(&(path[path_len]), ft_strlen(path));
        i++;
    }
}

void print_normal(char **arr) 
{ 
    int     i;
    
    i = 0;
    while (arr[i])
    {
        ft_printf("%s\n", arr[i]);  
        i++;
    }
}

void handle_recursion(char *path, t_info *info)
{
    DIR             *folder;
    int             path_len;

    path_len = ft_strlen(path);
    folder = opendir(path);

    while ((info->entry = readdir(folder)))
    { 
        path = ft_strcat(path, "/");
        path = ft_strcat(path, info->entry->d_name);
        stat(path, &info->filestat);
        if (S_ISDIR(info->filestat.st_mode))
        {
            if ((info->entry->d_name[0] != '.' || info->is_aflag) && (ft_strcmp(".", info->entry->d_name) && ft_strcmp("..", info->entry->d_name)))
            {
                ft_printf("%s:\n", path);
                handle_input(path, info);
            }
        }
        ft_bzero(&(path[path_len]), ft_strlen(path));
    }
    closedir(folder);
}