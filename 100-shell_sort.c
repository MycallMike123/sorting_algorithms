#include "sort.h"

void swap_integer(int *a, int *b);

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{

		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				swap_integer(array + b, array + (b - gap));
				b -= gap;
			}
		}

		print_array(array, size);
	}
}

/**
 * swap_integer - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_integer(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
