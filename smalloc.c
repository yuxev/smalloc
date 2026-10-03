#include "smalloc.h"

mt_data	*g_chunk;

static mt_data	*new_zone(unsigned int size)
{
	mt_data	*chunk;
	size_t	len;
	size_t	page;

	page = getpagesize();
	len = size + HDR;
	if (len < ZONE_SIZE)
		len = ZONE_SIZE;
	len = (len + page - 1) / page * page;
	chunk = mmap(NULL, len, (PROT_READ | PROT_WRITE),
			(MAP_PRIVATE | MAP_ANONYMOUS), -1, 0);
	if (chunk == MAP_FAILED)
		return (NULL);
	chunk->size = len - HDR;
	chunk->sts = false;
	chunk->chnk_addrs = (char *)chunk + HDR;
	chunk->next_chnuk = NULL;
	return (chunk);
}

static void	split_chunk(mt_data *chunk, unsigned int size)
{
	mt_data	*rest;

	if (chunk->size < size + HDR + ALIGN)
		return ;
	rest = (mt_data *)((char *)chunk->chnk_addrs + size);
	rest->size = chunk->size - size - HDR;
	rest->sts = false;
	rest->chnk_addrs = (char *)rest + HDR;
	rest->next_chnuk = chunk->next_chnuk;
	chunk->size = size;
	chunk->next_chnuk = rest;
}

static mt_data	*find_chunk(unsigned int size, mt_data **last)
{
	mt_data	*tmp;

	tmp = g_chunk;
	*last = NULL;
	while (tmp)
	{
		if (tmp->sts == false && tmp->size >= size)
			return (tmp);
		*last = tmp;
		tmp = tmp->next_chnuk;
	}
	return (NULL);
}

void	*smalloc(int size)
{
	mt_data			*chunk;
	mt_data			*last;
	unsigned int	sz;

	if (size <= 0)
		return (NULL);
	sz = ((unsigned int)size + ALIGN - 1) & ~(ALIGN - 1);
	chunk = find_chunk(sz, &last);
	if (!chunk)
	{
		chunk = new_zone(sz);
		if (!chunk)
			return (NULL);
		if (last)
			last->next_chnuk = chunk;
		else
			g_chunk = chunk;
	}
	split_chunk(chunk, sz);
	chunk->sts = true;
	return (chunk->chnk_addrs);
}
