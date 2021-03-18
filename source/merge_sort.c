#include "merge_sort.h"

static inline bool merge(void *ptr, void *temp, size_t left, size_t middle, size_t right, size_t size, int (*compare)(const void *, const void *))
{
    int i = left, j = middle + 1, k = left;

    memcpy(temp + left * size, ptr + left * size, (right - left + 1) * size);
    
    while (i <= middle && j <= right)
    {
        if (compare(temp + i * size, temp + j * size) > 0)
        {
            memcpy(ptr + k * size, temp + j * size, size);
            j++;
        }
        else
        {
            memcpy(ptr + k * size, temp + i * size, size);
            i++;
        }
        k++;
    }

    while (i <= middle)
    {
        memcpy(ptr + k * size, temp + i * size, size);
        i++;
        k++;
    }

    while (j <= right)
    {
        memcpy(ptr + k * size, temp + j * size, size);
        j++;
        k++;
    }

	return true;
}

static bool merge_sort_recursive(void *ptr, void *temp, size_t left, size_t right, size_t size, int (*compare)(const void *, const void *))
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        
        merge_sort_recursive(ptr, temp, left, middle, size, compare);
        merge_sort_recursive(ptr, temp, middle + 1, right, size, compare);
        
        merge(ptr, temp, left, middle, right, size, compare);
        
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * A função principal (merge_sort) é apenas uma WRAPPER da função que realmente faz a ordenação (merge_sort_recursive)
 * Isso foi feito para utilizar a notação usual do Merge Sort mas manter o padrão das outras funções nessa coleção
 * Além disso isso permite alocar e desalocar apenas uma região de memória para ser utilizada em toda a ordenação
 */
bool merge_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *))
{
	if (ptr == NULL || num <= 0 || size <= 0 || compare == NULL)
		return false;

    void *temp = calloc(num, size);

    bool result = merge_sort_recursive(ptr, temp, 0, num - 1, size, compare);

    free(temp);

	return result;
}