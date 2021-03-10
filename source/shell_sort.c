#include "shell_sort.h"

bool shell_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

	int h = 1;
	while (h < num)
		h = 3 * h + 1;

	void *buffer = calloc(size, 1);
	int i = 0, j = 0;

	while (h > 0)
	{
		h /= 3;

		for (i = h; i < num; i++)
		{
			j = i - h;

			memcpy(buffer, ptr + i * size, size);

			while (j >= 0 && compare(ptr + j * size, buffer) > 0)
			{
				memcpy(ptr + (j + h) * size, ptr + j * size, size);
				j -= h;
			}

			memcpy(ptr + (j + h) * size, buffer, size);
		}
	}

	return true;
}