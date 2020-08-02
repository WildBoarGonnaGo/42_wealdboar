#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_nputchar(char c, int n)
{
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
}

int	main(int argc, char **argv)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		argc = 1;
		while (argv[argc][i])
		{
			if (argv[argc][i] >= 'A' && argv[argc][i] <= 'Z')
			{
				count = (int)(argv[argc][i] - 'A' + 1);
				ft_nputchar(argv[argc][i], count);
				i++;
			}
			else if (argv[argc][i] >= 'a' && argv[argc][i] <= 'z')
			{
				count = (int)(argv[argc][i] - 'a' + 1);
				ft_nputchar(argv[argc][i], count);
				i++;
			}
			else
			{
				ft_putchar(argv[argc][i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
