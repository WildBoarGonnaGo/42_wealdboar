#include <unistd.h>

int	main(void)
{
	char c;
	int index;

	c = 97;
	index = 0;
	while (c <= 'z')
	{
		if (index % 2 == 0)
			write(1, &c, 1);
		else
		{
			c -= 32;
			write(1, &c, 1);
			c += 32;
		}
		index++;
		c++;
	}
	write(1, "\n", 1);
	return (0);
}
