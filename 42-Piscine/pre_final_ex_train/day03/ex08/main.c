#include <stdio.h>
#include <string.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

int		main(void)
{
	char	*str;
	int		num;

	str = "	 	+3";
	ft_putstr("Original string: ");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr("Number from a string: ");
	num = ft_atoi(str);
	ft_putnbr(num);
	ft_putchar('\n');
	printf("(%d)\n", num);
	return (0);
}
