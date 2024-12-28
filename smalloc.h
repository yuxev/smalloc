#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>

typedef struct t_metadata
{
	void				*chnk_addrs;
    unsigned int		size;
	bool				sts;
	struct t_metadata	*next_chnuk;
} mt_data;


void    *smalloc(int size);
void    s_free(void *addrs);