#include "ft_ls.h"

void initialize_var(t_info *info)
{
    info->is_aflag = 0;
    info->is_lflag = 0;
    info->is_tflag = 0;
    info->is_rflag = 0;
    info->is_Rflag = 0;
    info->i = 1;
}

int main(int __attribute__ ((unused)) argc, char **argv)
{
    t_info          info;

    initialize_var(&info);

    check_flag(argv, &info);

    handle_input(argv[info.i], &info);

    char *arr[] = {"Karol\n", "Kamil\n", "Pola\n", "!221\n", "Angela\n", "992111\n", "Kacper\n", "Jon\n", "Bob\n", "Aaron\n", "John\n", "Johnny\n", "Kamil\n", "Kazimierz\n"};
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printArray(arr, n); 

    return (0);
}