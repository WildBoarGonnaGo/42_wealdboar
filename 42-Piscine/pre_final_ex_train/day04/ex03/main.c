#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	int nb;
	int pow;

	nb = 5;
	pow = 3;
	printf("%d power %d:	%d\n", nb, pow, ft_recursive_power(nb, pow));
	return (0);
}
