#ifndef BOGO_SORT_H
#define BOGO_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool bogo_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* BOGO_SORT_H */