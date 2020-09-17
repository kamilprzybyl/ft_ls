#include "ft_ls.h"


void swap(char **a, char **b) 
{ 
    char *t = *a; 
    *a = *b; 
    *b = t; 
} 


void quickSort(char *arr[], int low, int high)
{
    int     pivot;
    int     start;
    int     end;

    pivot = low;
    start = low;
    end = high;

    if (low >= high)
        return;

    while (low < high)
    {
        if (low == pivot)
        {
            if (arr[high][0] > arr[pivot][0])
                high--;
            else if (arr[high][0] == arr[pivot][0])
            {
                int     i;

                i = 1;
                while (arr[high][i] == arr[pivot][i] && arr[high][i] && arr[pivot][i])
                    i++;
                if (arr[high][i] > arr[pivot][i])
                    high--;
                else if (arr[high][i] < arr[pivot][i])
                {
                    swap(&arr[high], &arr[pivot]);
                    pivot = high;
                }
                else
                    high--;
            }
            else if (arr[high][0] < arr[pivot][0])
            {
                swap(&arr[high], &arr[pivot]);
                pivot = high;
            }
        }
        else if (high == pivot)
        {
            if (arr[low][0] <= arr[pivot][0])
                low++;
            else if (arr[low][0] == arr[pivot][0])
            {
                int     i;

                i = 1;
                while (arr[low][i] == arr[pivot][i] && arr[high][i] && arr[pivot][i])
                    i++;

                if (arr[low][i] < arr[pivot][i])
                    low++;
                else if (arr[low][i] > arr[pivot][i])
                {
                    swap(&arr[low], &arr[pivot]);
                    pivot = low;
                }
                else
                    low++;
            }
            else if (arr[low][0] > arr[pivot][0])
            {
                swap(&arr[low], &arr[pivot]);
                pivot = low;
            }
        }
    }
    
    quickSort(arr, start, (pivot - 1));
    quickSort(arr, (pivot + 1), end);

    return;
}


void printArray(char *arr[], int size) 
{ 
    int i; 
    printf("Sorted array: \n"); 
    for (i=0; i < size; i++) 
        printf("%s", arr[i]); 
    printf("\n"); 
} 
