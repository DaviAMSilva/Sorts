#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool radix_sort(void *ptr, size_t num, size_t size, size_t buckets, size_t iterations, int (*categorize)(const void *, size_t));

#endif /* RADIX_SORT_H */