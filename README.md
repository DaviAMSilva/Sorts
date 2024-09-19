# Sorts

**Coleção de algoritmos de ordenação.**

Para as funções de comparação pense que o item de mais *importância* fica no final da lista, e a função deve retornar um número positivo se o primeiro parâmetro é mais *importante* do que o segundo, 0 se forem iguais e um número negativo nos outros casos.

## Ordenações suportadas

- [x] `libbinary_insertion_sort`
- [x] `libbogo_sort`
- [x] `libbubble_sort`
- [x] `libheap_sort`
- [x] `libinsertion_sort`
- [x] `libmerge_sort`
- [x] `libquick_sort`
- [x] `libradix_sort`
- [x] `libselection_sort`
- [x] `libshell_sort`

## Cabeçalhos

```c
bool binary_insertion_sort(void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool bogo_sort            (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool bubble_sort          (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool heap_sort            (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool insertion_sort       (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool merge_sort           (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool quick_sort           (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool radix_sort           (void *ptr, size_t num, size_t size, size_t buckets, size_t iterations, int (*categorize)(const void *, size_t));
bool selection_sort       (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
bool shell_sort           (void *ptr, size_t num, size_t size, int (*compare)(const void *, const void *));
```
