#include <stdio.h>
#include <dirent.h> /* opendir, readdir, closedir functions */
#include <string.h>
#include <sys/stat.h> /* stat function */
#include <time.h> /* ctime function */
#include <pwd.h> /* getpwuid funtion */
#include <grp.h> /* getgrgid function */



int main(int argc, char **argv)
{
    DIR             *folder;
    struct dirent   *entry;
    int             is_aflag;
    int             is_lflag;
    int             i;
    struct stat     filestat;
    char            *path;
    int             path_len;
    struct group    *grp;
    struct passwd   *pwd;

    is_aflag = 0;
    is_lflag = 0;
    i = 1;
    argc++;

    while (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "-l") == 0)
    {
        if (strcmp(argv[i], "-a") == 0)
            is_aflag = 1;
        else if (strcmp(argv[i], "-l") == 0)
            is_lflag = 1;
        i++;
    }
    
    path_len = strlen(argv[i]);
    folder = opendir(argv[i]);
    
    if (is_aflag && is_lflag)
    {
        while ((entry = readdir(folder)))
        {
            path = strcat(argv[i], entry->d_name);
            stat(path, &filestat);
            pwd = getpwuid(filestat.st_uid);
            grp = getgrgid(filestat.st_gid);

            printf( (S_ISDIR(filestat.st_mode)) ? "d" : "-");
            printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
            printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
            printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
            printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
            printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
            printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
            printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
            printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
            printf( (filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
            printf("%-3d", filestat.st_nlink);
            printf("%-14s", pwd->pw_name);
            printf("%-7s", grp->gr_name);
            printf("%-5lld", filestat.st_size);
            // printf("%s", ctime(&filestat.st_mtime));
            printf("%s", entry->d_name);
            printf("\n");
            bzero(&(path[path_len]), strlen(path));
        }
    }
    else if (is_lflag)
    {
        while ((entry = readdir(folder)))
        {
            path = strcat(argv[i], entry->d_name);
            stat(path, &filestat);
            pwd = getpwuid(filestat.st_uid);
            grp = getgrgid(filestat.st_gid);
            if (entry->d_name[0] != '.')
            {
                printf( (S_ISDIR(filestat.st_mode)) ? "d" : "-");
                printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
                printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
                printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
                printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
                printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
                printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
                printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
                printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
                printf( (filestat.st_mode & S_IXOTH) ? "x  " : "-  ");
                printf("%d  ", filestat.st_nlink);
                printf("%-14s", pwd->pw_name); 
                printf("%-7s", grp->gr_name);
                printf("%-5lld", filestat.st_size);
                // printf("%s", ctime(&filestat.st_mtime));
                printf("%s", entry->d_name);
                printf("\n");
            }
            bzero(&(path[path_len]), strlen(path));
        }
    }
    else if (is_aflag)
    {
        while ((entry = readdir(folder)))
            printf("%-12s", entry->d_name);

        printf("\n");
    }
    else
    {
        while ((entry = readdir(folder)))
            if (entry->d_name[0] != '.')
                printf("%-12s", entry->d_name);

        printf("\n");
    }
    

    // stat(argv[0], &filestat);
    // printf("File Size: \t\t%lld bytes\n", filestat.st_size);
    // printf("Number of Links: \t%d\n", filestat.st_nlink);
    // printf("File Permissions: \t");
    // printf( (S_ISDIR(filestat.st_mode)) ? "d" : "-");
    // printf( (filestat.st_mode & S_IRUSR) ? "r" : "-");
    // printf( (filestat.st_mode & S_IWUSR) ? "w" : "-");
    // printf( (filestat.st_mode & S_IXUSR) ? "x" : "-");
    // printf( (filestat.st_mode & S_IRGRP) ? "r" : "-");
    // printf( (filestat.st_mode & S_IWGRP) ? "w" : "-");
    // printf( (filestat.st_mode & S_IXGRP) ? "x" : "-");
    // printf( (filestat.st_mode & S_IROTH) ? "r" : "-");
    // printf( (filestat.st_mode & S_IWOTH) ? "w" : "-");
    // printf( (filestat.st_mode & S_IXOTH) ? "x" : "-");
    // printf("\n");

    closedir(folder);

    return (0);
}