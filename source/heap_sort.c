#include "heap_sort.h"

static bool swap(void *a, void *b, void *buffer, size_t size)
{
	if (a == NULL || b == NULL || buffer == NULL || size <= 0)
		return false;

	// ¯\_(ツ)_/¯
	memcpy(buffer, a, size);
	memcpy(a, b, size);
	memcpy(b, buffer, size);

	return true;
}

static void heapify(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *), void *buffer, size_t index)
{
	size_t largest = index;
	size_t left  = (index << 1) + 1;
	size_t right = (index + 1) << 1;

	if (left < num && compare(ptr + left * size, ptr + largest * size) > 0)
		largest = left;

	if (right < num && compare(ptr + right * size, ptr + largest * size) > 0)
		largest = right;

	if (largest != index)
	{
		swap(ptr + largest * size, ptr + index * size, buffer, size);
		heapify(ptr, num, size, compare, buffer, largest);
	}
}

bool heap_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	void *buffer = calloc(1, size);

	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL || buffer == NULL)
		return false;

	for (int i = (num - 2) / 2;i >= 0; i--)
	{
		heapify(ptr, num, size, compare, buffer, i);
	}

	while (num > 1)
	{
		swap(ptr + 0 * size, ptr + (num - 1) * size, buffer, size);
		num--;

		heapify(ptr, num, size, compare, buffer, 0);
	}

	free(buffer);

	return true;
}