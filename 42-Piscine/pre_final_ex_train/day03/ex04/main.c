#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int	a;
	int b;

	a = 48;
	b = 5;
	printf("Numbers before changes: %d %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("Numbers after changes: %d %d\n", a, b);
	return (0);
}
