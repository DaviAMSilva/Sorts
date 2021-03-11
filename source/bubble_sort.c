#include "bubble_sort.h"

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

bool bubble_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

	void *buffer = calloc(size, 1);
	bool swapped = false;

	for (int i = 0; i < num - 1; i++)
	{
		swapped = false;

		for (int j = 0; j < num - 1 - i; j++)
		{
			if (compare(ptr + j * size, ptr + (j + 1) * size) > 0)
			{
				swap(ptr + j * size, ptr + (j + 1) * size, buffer, size);
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}

	return true;
}