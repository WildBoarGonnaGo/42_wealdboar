#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	int nb = 8;
	printf("Factorial of %d:	%d\n", nb, ft_iterative_factorial(nb));
	return (0);
}
