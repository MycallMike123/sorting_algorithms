#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b, min_idx;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min_idx = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_idx])
				min_idx = b;
		}

		if (min_idx != a)
		{
			tmp = array[a];
			array[a] = array[min_idx];
			array[min_idx] = tmp;

			print_array(array, size);
		}
	}
}
