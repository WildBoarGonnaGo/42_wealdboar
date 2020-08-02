#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int	a;
	int b;
	int div;
	int mod;

	a = 12;
	b = 5;
	div = 0;
	mod = 0;
	printf("Numbers before changes: %d %d\n", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("Numbers after changes: %d %d\n", div, mod);
	return (0);
}
