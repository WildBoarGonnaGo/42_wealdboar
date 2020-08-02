#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char i[3];

	i[0] = '0';
	while (i[0] <= '7')
	{
		i[1] = i[0] + 1;
		while (i[1] <= '8')
		{
			i[2] = i[1] + 1;
			while (i[2] <= '9')
			{
				ft_putchar(i[0]);
				ft_putchar(i[1]);
				ft_putchar(i[2]);
				if (i[0] != '7')
					ft_putchar(',');
				if (i[0] != '7')
					ft_putchar(' ');
				i[2]++;
			}
			i[1]++;
		}
		i[0]++;
	}
	ft_putchar('\n');
}
