#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool bubble_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* BUBBLE_SORT_H */