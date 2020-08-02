#include <stdio.h>
#include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

int		main(void)
{
	char	*str;
	int		str_len;

	str = "ZA WARDO! Toki wo tomare!";
	ft_putstr(str);
	str_len = ft_strlen(str);
	ft_putchar('\n');
	printf("System string length:	%lu\n", strlen(str));
	printf("My string length:	%d\n", str_len);
	return (0);
}
