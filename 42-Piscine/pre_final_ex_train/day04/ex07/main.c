#include <stdio.h>

int		ft_find_next_prime(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

int		main(int argc, char **argv)
{
	int nb;
	argc = 1;

	nb = ft_atoi(argv[argc]);
	printf("Next prime number after %d:	%d\n", nb, ft_find_next_prime(nb));
	return (0);
}
