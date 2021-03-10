#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool insertion_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* INSERTION_SORT_H */