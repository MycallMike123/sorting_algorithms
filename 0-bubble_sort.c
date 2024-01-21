#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order by bubblr sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp, swap;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		swap = 0;
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;

				print_array(array, size);
				swap = 1;
			}
		}

		if (swap == 0)
			break;
	}
}
