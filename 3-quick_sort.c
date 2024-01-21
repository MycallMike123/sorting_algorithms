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

	lomuto_partition(array, size, 0, size - 1);
}

/**
 * recursive_quick_sort - Recursive helper function for Quick Sort
 * @a: The first int to swap
 * @b: The second int to swap
 */

void recursive_quick_sort(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index
 */

void lomuto_partition(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = _lomuto_partition(array, size, left, right);
		lomuto_partition(array, size, left, partition - 1);
		lomuto_partition(array, size, partition + 1, right);
	}
}

/**
 * _lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme (last element as pivot)
 * @array: The array of ints
 * @size: The size of the array
 * @left: The starting index
 * @right: The ending index
 * Return: The final partition index.
 */
int _lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;

	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				recursive_quick_sort(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		recursive_quick_sort(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}
