#include "mini_paint.h"

int main(int argc, char **argv)
{	
	FILE *fd;
	t_crcl obj;
	int st;

	memset(&obj, 0, sizeof(obj) - 1);
	if (argc != 2)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (1);
	}
	if (!(fd = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	while ((st = check_row(fd, &obj)))
	{
		if (st < 0)
			break ;
	}
	if (st < 0)
	{
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	print_arr(&obj);
	free_arr(&obj);
	return (0);
}
