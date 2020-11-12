#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);
int		ft_atoi_base(char *str, char *base);

int		main(void)
{
	int		len;
	char	*str;
	char	*src = "Tsugi wa Jotaro! Kisama da";
	char	*dst;
	char	*hell = "What the hel!";
	char	*yell = "What the hell";
	char	*sdup;
	ssize_t	errs[2];

	ft_putchar('C');
	ft_putchar('\n');
	str = (char *)malloc(ft_strlen(src));
	len = ft_strlen(src);
	printf("Length of string: %d\n", len);
	dst = ft_strcpy(str, src);
	printf("Copy of string: %s\n", dst);
	len = ft_strcmp(hell, yell);
	printf("Diffrence between two strings: %d\n", len);
	printf("Diffrence between two strings with two strcmp: %d\n", strcmp(hell, yell));
	sdup = ft_strdup(src);
	printf("copied string: %s\n", sdup);
	errs[0] = write(-1, "Hello\n", 6);
	errs[1] = ft_write(-1, "Hello\n", 6);
	printf("Error code of original write (errs[0]): %zd\n", errs[0]);
	printf("Error code of user\'s write (errs[1]): %zd\n", errs[1]);
	printf("Integer value of \'11111111b\': %d\n", ft_atoi_base("0000000011111111", "01"));
	free(sdup);
	free(str);	
	return(0);
}
