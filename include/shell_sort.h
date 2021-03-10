#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool shell_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif /* SHELL_SORT_H */