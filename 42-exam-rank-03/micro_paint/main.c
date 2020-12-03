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

void	print_field(t_rctngl *obj)
{
	int	pos[2];

	pos[0] = -1;
	while (++pos[0] < obj->height)
	{
		pos[1] = -1;
		while (++pos[1] < obj->width)
		{
			write(1, (char *)&obj->field[pos[0]][pos[1]], 1);
			if (pos[1] == obj->width - 1)
				write(1, "\n", 1);
		}	
	}	
}

int 	main(int argc, char *argv[])
{
	FILE		*fd;
	t_rctngl	obj;
	int			st;

	memset(&obj, 0, sizeof(obj) - 1);
	if (argc == 1 || argc > 2)
	{
		write(1, "Error: argument\n", ft_strlen("Error: argument\n"));
		return (1);
	}
	if (!(fd = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	while ((st = check_row(fd, &obj)) > 0)
		obj.eol = 0;
	if (st < 0)
	{
		write(1, "Error: Operation file corrupted\n", ft_strlen("Error: Operation file corrupted\n"));
		return (1);
	}
	print_field(&obj);
	return (0);
}
