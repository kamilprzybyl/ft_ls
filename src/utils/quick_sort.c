#include "../../inc/ft_ls.h"

static void	swap_str(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

void	quick_sort_str(char *arr[], int low, int high)
{
	int	pivot;
	int	start;
	int	end;

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
			else if (arr[high][0] == arr[pivot][0]) // if first chars of strings are equal check the remaining part (char by char)
			{
				int	i;

				i = 1;
				while (arr[high][i] == arr[pivot][i] && arr[high][i] && arr[pivot][i])
					i++;
				if (arr[high][i] > arr[pivot][i])
					high--;
				else if (arr[high][i] < arr[pivot][i])
				{
					swap_str(&arr[high], &arr[pivot]);
					pivot = high;
				}
				else
					high--;
			}
			else if (arr[high][0] < arr[pivot][0])
			{
			swap_str(&arr[high], &arr[pivot]);
			pivot = high;
			}
		}
		else if (high == pivot)
		{
			if (arr[low][0] <= arr[pivot][0])
				low++;
			else if (arr[low][0] == arr[pivot][0])
			{
				int	i;

				i = 1;
				while (arr[low][i] == arr[pivot][i] && arr[high][i] && arr[pivot][i])
					i++;
				if (arr[low][i] < arr[pivot][i])
					low++;
				else if (arr[low][i] > arr[pivot][i])
				{
					swap_str(&arr[low], &arr[pivot]);
					pivot = low;
				}
				else
					low++;
			}
			else if (arr[low][0] > arr[pivot][0])
			{
				swap_str(&arr[low], &arr[pivot]);
				pivot = low;
			}
		}
	}
	quick_sort_str(arr, start, (pivot - 1));
	quick_sort_str(arr, (pivot + 1), end);
	return;
}

static void	swap_struct(t_file *a, t_file *b)
{
	t_file	t;

	t = *a;
	*a = *b;
	*b = t;
}

/* a quick sort below sort structure by its last_modified value */
void quick_sort_struct(t_file *struct_arr, int low, int high)
{
	int	pivot;
	int	start;
	int	end;

	pivot = low;
	start = low;
	end = high;
	if (low >= high)
		return;
	while (low < high)
	{
		if (low == pivot)
		{
			if (struct_arr[high].last_modified <= struct_arr[pivot].last_modified)
				high--;
			else if (struct_arr[high].last_modified > struct_arr[pivot].last_modified)
			{
				swap_struct(&struct_arr[high], &struct_arr[pivot]);
				pivot = high;
			}
		}
		else if (high == pivot)
		{
			if (struct_arr[low].last_modified >= struct_arr[pivot].last_modified)
				low++;
			else if (struct_arr[low].last_modified < struct_arr[pivot].last_modified)
			{
				swap_struct(&struct_arr[low], &struct_arr[pivot]);
				pivot = low;
			}
		}
	}
	quick_sort_struct(struct_arr, start, (pivot - 1));
	quick_sort_struct(struct_arr, (pivot + 1), end);
	return;
}
