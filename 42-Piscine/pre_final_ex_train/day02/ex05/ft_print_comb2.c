#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putchar(a / 10 + 48);
			ft_putchar((a - a / 10 * 10) + 48);
			ft_putchar(' ');
			ft_putchar(b / 10 + 48);
			ft_putchar((b - b / 10 * 10) + 48);
			if (a != 98)
				ft_putchar(',');
			if (a != 98)
				ft_putchar(' ');
			b++;
		}
		a++;
	}
	ft_putchar('\n');
}


