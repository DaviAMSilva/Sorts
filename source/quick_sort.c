#include "quick_sort.h"

static int median(void *ptr, size_t size, int (*compare)(const void *, const void *), int start, int end)
{
    int middle = start + ((end - start) >> 1);

    // (s > m) ^ (s > e)
    if ((compare(ptr + start * size, ptr + middle * size) > 0) ^ (compare(ptr + start * size, ptr + end * size) > 0))
        return start;
    // (m < s) ^ (m < e)
    else if ((compare(ptr + middle * size, ptr + start * size) < 0) ^ (compare(ptr + middle * size, ptr + end * size) < 0))
        return middle;
    else
        return end;
}

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

static int partition(void *ptr, size_t size, int (*compare)(const void *, const void *), void *value, void *buffer, int start, int end)
{
	int index = start;
    
    // Utilizando a estratégia da mediana de 3 números
    swap(ptr + median(ptr, size, compare, start, end) * size, ptr + end * size, buffer, size);

	memcpy(value, ptr + end * size, size);

	for (int i = start; i <= end - 1; i++)
	{
		if (compare(ptr + i * size, value) < 0)
		{
			swap(ptr + i * size, ptr + index * size, buffer, size);
			index++;
		}
	}

	swap(ptr + index * size, ptr + end * size, buffer, size);

	return index;
}

static bool quick_sort_recursive(void *ptr, size_t size, int (*compare)(const void *, const void *), void *value, void *buffer, int start, int end)
{
	if (start >= end)
		return false;

	int index = partition(ptr, size, compare, value, buffer, start, end);

	quick_sort_recursive(ptr, size, compare, value, buffer, start, index - 1);
	quick_sort_recursive(ptr, size, compare, value, buffer, index + 1, end);

	return true;
}

bool quick_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	void *value  = calloc(1, size),
		 *buffer = calloc(1, size);

	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL || value == NULL || buffer == NULL)
		return false;

	bool result = quick_sort_recursive(ptr, size, compare, value, buffer, 0, num - 1);

	free(value);
	free(buffer);

	return result;
}