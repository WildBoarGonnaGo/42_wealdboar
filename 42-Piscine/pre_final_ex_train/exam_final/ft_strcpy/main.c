#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2);

int	main(void)
{
	char *s1;
	char *s2;

	s2 = "ZA WARUDO! Tokio tomare!";
	s1 = (char*)malloc(100);
	s1 = ft_strcpy(s1, "Chikadzu kanaka teme wo buchi no me tenain de na");
	printf("Original string: %s\n", s2);
	printf("Copied string: %s\n", s1);
	return (0);
}
