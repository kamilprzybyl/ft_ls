#include "../inc/ft_ls.h"

void handle_tflag(char **arr, char *path, t_data *data, int arr_len)
{
    int             path_len;
    int             i;
    t_file          tfile[arr_len];

    i = 0;
    /* In the loop below we have to create a struct which will keep a file name and its last modified time */
    while (arr[i])
    {
        path_len = ft_strlen(path);
        path = strcat(path, "/");
        path = strcat(path, arr[i]);
        stat(path, &data->filestat);

        tfile[i].name = malloc(254 * sizeof(char));
        strcpy(tfile[i].name, arr[i]);
        tfile[i].last_modified = data->filestat.st_mtime;
        ft_bzero(&(path[path_len]), ft_strlen(path));
        i++;
    }        
    quick_sort_struct(tfile, 0, arr_len-1);

    i = 0;
    /* now from already sorted struct array we have to copy file names to an arr because we don't want to keep it in a structure (because our print functions do not read from structure but from array of strings)*/
    while (arr[i])
    {
        ft_bzero(arr[i], ft_strlen(arr[i]));
        strcpy(arr[i], tfile[i].name);
        free(tfile[i].name);
        i++;
    }
}
