#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	int nb = 5;
	printf("Factorial of %d:	%d\n", nb, ft_recursive_factorial(nb));
	return (0);
}
