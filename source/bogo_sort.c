#include "bogo_sort.h"

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

static bool sorted(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	for (int i = 1; i < num; i++)
		if (compare(ptr + (i - 1) * size, ptr + i * size) > 0)
			return false;

	return true;
}

bool bogo_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

	void *buffer = calloc(size, 1);

	while (!sorted(ptr, num, size, compare))
	{	
		for (int i = 0; i < num; i++)
		{
			int r = rand() % num;
			
			if (i != r)
				// Muito lento, mas isso não é mesmo uma preocupação
				swap(ptr + i * size, ptr + r * size, buffer, size);
		}
	}

	return true;
}