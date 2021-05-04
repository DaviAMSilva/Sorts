#include "radix_sort.h"

static bool counting_sort(void *ptr, size_t num, size_t size, size_t buckets, size_t iteration, int (*categorize)(const void *, size_t), void *buffer, size_t *count)
{
	memset(count, 0, sizeof(size_t) * buckets);

	for (int i = 0; i < num; i++)
	{
		count[categorize(ptr + i * size, iteration)]++;
	}

	for (int i = 1; i < buckets; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = num - 1; i >= 0; i--)
	{
		memcpy(buffer + (count[categorize(ptr + i * size, iteration)] - 1) * size, ptr + i * size, size);
		count[categorize(ptr + i * size, iteration)]--;
	}

	memcpy(ptr, buffer, size * num);

	return true;
}

/**
 * Essa função é completamente absurda. Todas as outras funções nessa biblioteca utilizam callbacks de comparação,
 * entretanto o radix_sort utiliza um método diferente que divide os itens com base em valores númericos. Assim foi
 * preciso adaptar esse método da seguinte maneira:
 * 1. O parâmetro buckets guarda a quantidade de "baldes" para separar os itens em cada iteração do algoritmo
 * 2. O parâmetro iterations indica quantas iterações o algoritmo deverá percorrer (já que este não pode ser calculado)
 * 3. O parâmetro categorize é uma função cujo objetivo é retornar o índice do balde em que determinado item irá cair
 *    em determinada iteração, indicados pelos parâmetros da função categorize
 */
bool radix_sort(void *ptr, size_t num, size_t size, size_t buckets, size_t iterations, int (*categorize)(const void *, size_t))
{
	void *buffer = calloc(num, size);
	size_t *count = calloc(buckets, sizeof(size_t));

	if (ptr == NULL || num <= 0 || size <= 0 || buckets <= 0 || iterations <= 0 || categorize == NULL || buffer == NULL || count == NULL)
		return false;

	for (int i = 0; i < iterations; i++)
	{
		counting_sort(ptr, num, size, buckets, i, categorize, buffer, count);
	}

	free(buffer);
	free(count);

	return true;
}