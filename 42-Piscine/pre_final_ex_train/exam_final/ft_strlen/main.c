#include <stdio.h>

int	ft_strlen(char *s1);

int	main(void)
{
	char *s1;

	s1 = "Chikadzu kanaka teme wo buchi no me tenain de na";
	printf("Input string: %s\n", s1);
	printf("Length of string: %d\n", ft_strlen(s1));
	return (0);
}
