#include "selection_sort.h"

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

bool selection_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

	void *buffer = calloc(size, 1);

	for (int i = 0; i < num; i++)
	{
		int index = i;

		for (int j = i + 1; j < num; j++)
			if (compare(ptr + index * size, ptr + j * size) > 0)
				index = j;

		if (false == swap(ptr + i * size, ptr + index * size, buffer, size))
			return false;
	}

	return true;
}