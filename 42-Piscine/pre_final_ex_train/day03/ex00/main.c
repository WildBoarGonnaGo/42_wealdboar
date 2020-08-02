#include <stdio.h>

void	ft_ft(int *nbr);

int main(void)
{
	int	a;

	a = 15;
	printf("Number before changes: %d\n", a);
	ft_ft(&a);
	printf("Number after changes: %d\n", a);
	return (0);
}
