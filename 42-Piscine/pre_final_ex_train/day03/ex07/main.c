#include <stdio.h>
#include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strrev(char *str);

int		main(void)
{
	char	*str;
	char	*lol;
	int		str_len;
	char 	new_str[] = "ZA WARDO! Toki wo tomare!";
	str = "ZA WARDO! Toki wo tomare!";
	ft_putstr(str);
	str_len = ft_strlen(str);
	ft_putchar('\n');
	printf("System string length:	%lu\n", strlen(str));
	printf("My string length:	%d\n", str_len);
	lol = ft_strrev(new_str);
	printf("Reversed string:	%s\n", new_str);
	lol = ft_strrev(str);
	printf("Reversed string:	%s\n", str);
	return (0);
}
