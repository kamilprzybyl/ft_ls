#include <stdio.h>
#include <dirent.h> /* opendir, readdir, closedir functions */


int main(int argc, char **argv)
{
    DIR             *folder;
    struct dirent   *entry;
    int             files;

    folder = opendir(argv[1]);

    if(folder == NULL)
    {
        puts("Unable to read directory");
        return(1);
    }
    
    while ((entry = readdir(folder)))
    {
        files++;
        if (entry->d_name[0] != '.')
            printf("%s   ", entry->d_name);
    }
    printf("\n");

    closedir(folder);

    return (0);
}