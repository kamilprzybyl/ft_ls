#include "../../inc/ft_ls.h"

void	rverese_array(char *arr[], int start, int end)
{
	char	*temp;

	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
