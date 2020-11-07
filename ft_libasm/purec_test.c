#include <stdio.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);

int		main(void)
{
	int	len;

	ft_putchar('C');
	ft_putchar('\n');
	len = ft_strlen("");
	printf("Length of string: %d\n", len);
	return(0);
}
