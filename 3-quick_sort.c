#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm (Lomuto partition scheme)
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursive helper function for Quick Sort
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Number of elements in the array
 */

void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high, size);
		recursive_quick_sort(array, low, pivot_idx - 1, size);
		recursive_quick_sort(array, pivot_idx + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * @size: Number of elements in the array
 * Return: The pivot index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp, a, b;

	pivot = array[high];
	a = low - 1;

	for (b = low; b <= high - 1; b++)
	{
		if (array[b] <= pivot)
		{
			a++;
			tmp = array[a];
			array[a] = array[b];
			array[b] = tmp;

			print_array(array, size);
		}
	}

	tmp = array[a + 1];
	array[a + 1] = array[high];
	array[high] = tmp;

	return (a + 1);
}
