#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
	*str = '\0';
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		argc = 1;
		ft_putstr(argv[argc]);
		ft_putchar('\n');
		return (0);		
	}
}
