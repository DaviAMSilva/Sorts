#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool merge_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* MERGE_SORT_H */