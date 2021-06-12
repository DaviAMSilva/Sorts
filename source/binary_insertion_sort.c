#include "binary_insertion_sort.h"

static long binary_search(void *ptr, size_t num, size_t size, void *data, int (*compare)(const void *, const void *), long low, long high)
{
    if (high <= low)
        return compare(data, ptr + low * size) > 0 ? low + 1 : low;

    long middle = low + ((high - low) >> 1);

    int cmp = compare(ptr + middle * size, data);

    if (cmp > 0)
        return binary_search(ptr, num, size, data, compare, low, middle - 1);
    else if (cmp < 0)
        return binary_search(ptr, num, size, data, compare, middle + 1, high);
    else
        return middle + 1;
}

bool binary_insertion_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    void *buffer = calloc(size, 1);
    int i = 0, j = 0, index = 0;

    if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL || buffer == NULL)
        return false;

    for (int i = 1; i < num; i++)
        if (compare(ptr + i * size, ptr + (i - 1) * size) < 0)
            return false;

    for (i = 1; i < num; i++)
    {
        j = i - 1;

        memcpy(buffer, ptr + i * size, size);

        index = binary_search(ptr, num, size, buffer, compare, 0, j);

        while (j >= 0 && compare(ptr + j * size, ptr + index * size) >= 0)
        {
            memcpy(ptr + (j + 1) * size, ptr + j * size, size);
            j--;
        }

        memcpy(ptr + (j + 1) * size, buffer, size);
    }

    return true;
}