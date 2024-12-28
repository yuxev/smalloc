#include "smalloc.h"

static	mt_data	*g_chunk;

void    *smalloc(int size)
{
	// a basic implementation to understand how should i start
	if (size <= 0)
		return (NULL);
	g_chunk = mmap(NULL, (sizeof(mt_data) + size), (PROT_READ | PROT_WRITE), (MAP_PRIVATE | MAP_ANONYMOUS), -1, 0);
	if (g_chunk == MAP_FAILED)
        return (NULL);
	g_chunk->size = size;
	g_chunk->sts = true;
	g_chunk->chnk_addrs = (void *)((char *)g_chunk + sizeof(mt_data));
	g_chunk->next_chnuk = NULL;
	return (g_chunk->chnk_addrs);
}

void    s_free(void *addrs)
{

}

int main(void)
{
	int size = 1000;
	void *p = smalloc(size);
	for (size_t i = 0; i < size; i++)
	{
		((char*)p)[i] = 'a';
		printf("%c\n", ((char*)p)[i]);
	}
	
}