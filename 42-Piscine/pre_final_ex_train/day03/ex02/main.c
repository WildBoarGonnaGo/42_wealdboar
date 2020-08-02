#include <stdio.h>

void	ft_swap(int *a, int *b);

int main(void)
{
	int	a;
	int b;

	a = 15;
	b = 42;
	printf("Numbers before changes: %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("Numbers after changes: %d %d\n", a, b);
	return (0);
}
