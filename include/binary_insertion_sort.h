#ifndef BINARY_INSERTION_SORT_H
#define BINARY_INSERTION_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool binary_insertion_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* BINARY_INSERTION_SORT_H */