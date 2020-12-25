#include "mini_paint.h"

int	ft_strlen(const char *str)
{
	int len;

	len = -1;
	while (*(str + ++len))
		;
	return (len);
}

int	ft_ceil(float a)
{
	if ((a - (int)a) > 0)
		return ((int)a + 1);
	return ((int)a);
}

void	free_arr(t_crcl *obj)
{
	int i;

	i = -1;
	while (++i < obj->h)
	{
		free(obj->arr[i]);
		obj->arr[i] = NULL;
	}
	free(obj->arr);
	obj->arr = NULL;
}

void	print_arr(t_crcl *obj)
{
	int pos[2];

	pos[0] = -1;
	while (++pos[0] < obj->h)
	{
		pos[1] = -1;
		while (++pos[1] < obj->w)
		{
			write(1, &obj->arr[pos[0]][pos[1]], 1);
			if (pos[1] == obj->w - 1)
				write(1, "\n", 1);
		}
	}
}


void	create_arr(t_crcl *obj)
{
	int pos[2];

	obj->arr = (int **)calloc(obj->h, sizeof(int *));
	pos[0] = -1;
	while (++pos[0] < obj->h)
		obj->arr[pos[0]] = (int *)calloc(obj->w, sizeof(int));
	pos[0] = -1;
	while (++pos[0] < obj->h)
	{
		pos[1] = -1;
		while (++pos[1] < obj->w)
			obj->arr[pos[0]][pos[1]] = obj->bk;
	}
}

void	create_empty(t_crcl *obj)
{
	int ac = -1;
	int	pos[3];
	
	obj->ry = 0;
	while (++ac < 360)
	{
		pos[0] = (int)(obj->y + obj->ry);
		pos[1] = (int)(obj->x + obj->rx);
		if (pos[0] >= 0 && pos[0] < obj->h && pos[1] >= 0 && pos[1] < obj->w)
			obj->arr[pos[0]][pos[1]] = obj->stt;
		pos[2] = obj->rx;
		obj->rx = obj->rx * DAX - obj->ry * DAY;
		obj->ry = pos[2] * DAY + obj->ry * DAX;
	}
}

void	create_fill(t_crcl *obj)
{
	int ac = -1;
	int	pos[3];
	float buf;

	obj->ry = 0;
	buf = obj->rx;
	while (obj->rx > 0)
	{
		while (++ac < 360)
		{
			pos[0] = (int)(obj->x + obj->rx);
			pos[1] = (int)(obj->y + obj->ry);
			if (pos[0] >= 0 && pos[0] < obj->h && pos[1] >= 0 && pos[1] < obj->w)
				obj->arr[pos[0]][pos[1]] = obj->stt;
			pos[2] = obj->rx;
			obj->rx = obj->rx * DAX - obj->ry * DAY;
			obj->ry = pos[2] * DAY + obj->ry * DAX;
		}
		ac = -1;
		obj->rx = --buf;
	   	
	}
}

int	check_row(FILE *fd, t_crcl *obj)
{
	int st;

	if (!obj->row)
	{
		++obj->row;
		st = fscanf(fd, "%d %d %c%c", &obj->w, &obj->h, &obj->bk, &obj->eol);
		if (st != 4)
			return (-1);
		st = (obj->w <= 0 || obj->w > 300 || obj->h <= 0 || obj->h > 300);
		if (st)
			return (-1);
		create_arr(obj);
	}
	else
	{
		st = fscanf(fd, "%c %f %f %f %c%c", &obj->st, &obj->x, &obj->y, &obj->rx, &obj->stt, &obj->eol);
		if (st != 6 || !obj->rx || (obj->st != 'c' && obj->st != 'C') || obj->rx < 0)
			return (-1);
		if (st == -1)
			return (0);
		(obj->st = 'c') ? create_empty(obj) : create_fill(obj);
	}
	return (1);
}
