#ifndef SMALLOC_H
# define SMALLOC_H

# include <string.h>
# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define ALIGN 16
# define ZONE_SIZE 16384

typedef struct t_metadata
{
	void				*chnk_addrs;
	unsigned int		size;
	bool				sts;
	struct t_metadata	*next_chnuk;
}	mt_data;

# define HDR ((sizeof(mt_data) + ALIGN - 1) & ~(ALIGN - 1))

extern mt_data	*g_chunk;

void	*smalloc(int size);
void	s_free(void *addrs);
void	show_mem(void);

#endif
