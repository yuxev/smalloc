#include "smalloc.h"

static void	fill(char *p, char c, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
		p[i++] = c;
	p[i] = '\0';
}

int	main(void)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	a = smalloc(1000);
	b = smalloc(42);
	c = smalloc(5000);
	fill(a, 'a', 1000);
	fill(b, 'b', 42);
	fill(c, 'c', 5000);
	printf("a: %.10s... %zu chars\n", a, strlen(a));
	show_mem();
	s_free(b);
	s_free(a);
	printf("\nafter s_free(b) and s_free(a):\n");
	show_mem();
	d = smalloc(500);
	if (d == a)
		printf("\nsmalloc(500) reused the old spot of a\n");
	show_mem();
	s_free(d);
	s_free(c);
	printf("\nafter freeing everything:\n");
	show_mem();
	return (0);
}
