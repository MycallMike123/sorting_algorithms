#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t b, a;
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			b = a;

			while (array[b - gap] > temp && b >= gap)
			{
				array[b] = array[b - gap];
				print_array(array, size);

				b -= gap;
			}

			array[b] = temp;
		}

		gap = (gap - 1) / 3;
	}
}
