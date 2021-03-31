#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool quick_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* QUICK_SORT_H */