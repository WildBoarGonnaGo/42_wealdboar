#include "micro_paint.h"

void	reset(t_rctngl *obj)
{
	int	field;
	int i;

	i = -1;
	field = sizeof(*obj);
	while (++i < field)
		*(char *)(obj + i) = 0;
}

int 	main(int argc, char *argv[])
{
	if (!argc || argc > 1)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (1);
	}
	
}
