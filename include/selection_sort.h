#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool selection_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* SELECTION_SORT_H */