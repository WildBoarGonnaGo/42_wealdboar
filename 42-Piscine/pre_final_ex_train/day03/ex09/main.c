#include <stdio.h>
#include <string.h>

void	ft_sort_integer_table(int *tab, int size);

int		main(void)
{
	int		num[] = {10, 9, 8, 7, 6 ,5, 4, 3, 2, 1};
	int		index = 0;
	int		size = 10;

	while (index < size)
	{
		printf("%d ", num[index]);
		index++;	
	}
	printf("\n");
	index = 0;
	ft_sort_integer_table(num, size);
	while (index < size)
	{
		printf("%d ", num[index]);
		index++;
	}
	printf("\n");
	return (0);
}
