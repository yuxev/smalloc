#include "smalloc.h"

static void	merge_next(mt_data *chunk)
{
	mt_data	*next;

	next = chunk->next_chnuk;
	while (next && next->sts == false
		&& (char *)chunk->chnk_addrs + chunk->size == (char *)next)
	{
		chunk->size += HDR + next->size;
		chunk->next_chnuk = next->next_chnuk;
		next = chunk->next_chnuk;
	}
}

void	s_free(void *addrs)
{
	mt_data	*tmp;
	mt_data	*prev;

	if (!addrs)
		return ;
	tmp = g_chunk;
	prev = NULL;
	while (tmp && tmp->chnk_addrs != addrs)
	{
		prev = tmp;
		tmp = tmp->next_chnuk;
	}
	if (!tmp || tmp->sts == false)
		return ;
	tmp->sts = false;
	merge_next(tmp);
	if (prev && prev->sts == false)
		merge_next(prev);
}

void	show_mem(void)
{
	mt_data	*tmp;
	size_t	total;

	tmp = g_chunk;
	total = 0;
	while (tmp)
	{
		printf("%p - %p : %6u bytes ", tmp->chnk_addrs,
			(void *)((char *)tmp->chnk_addrs + tmp->size), tmp->size);
		if (tmp->sts)
		{
			printf("used\n");
			total += tmp->size;
		}
		else
			printf("free\n");
		tmp = tmp->next_chnuk;
	}
	printf("total used: %zu bytes\n", total);
}
