#include <stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	int nb;
	
	nb = 9;
	printf("Fibonacci %d:	%d\n", nb, ft_fibonacci(nb));
	return (0);
}
