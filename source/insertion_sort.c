#include "insertion_sort.h"

bool insertion_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

	void *buffer = calloc(size, 1);
	int i = 0, j = 0;

	for (i = 1; i < num; i++)
	{
		j = i - 1;
		
		memcpy(buffer, ptr + i * size, size);

		while (j >= 0 && compare(ptr + j * size, buffer) > 0)
		{
			memcpy(ptr + (j + 1) * size, ptr + j * size, size);
			j--;
		}

		memcpy(ptr + (j + 1) * size, buffer, size);
	}

	return true;
}