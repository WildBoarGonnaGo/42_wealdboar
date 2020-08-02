#include <stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	int nb;
	int pow;

	nb = 2;
	pow = 8;
	printf("%d power %d:	%d\n", nb, pow, ft_iterative_power(nb, pow));
	return (0);
}
