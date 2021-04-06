#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool heap_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* HEAP_SORT_H */