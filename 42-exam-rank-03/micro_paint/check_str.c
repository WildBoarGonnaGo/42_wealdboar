#include "micro_paint.h"

int	check_row(FILE *fd, t_rctngl *obj)
{
	obj->i = 0;
	if (!obj->row)
	{
		++obj->row;
		obj->i = fscanf(fd, "%d %d %c%c", &obj->width, &obj->height, &obj->back, &obj->eol);
		if (obj->i != 4)
			return (-1);
		obj->i = ((obj->width < 0 && obj->width > 300) ||
		(obj->height < 0 && obj->height > 300));
		if (obj->i)
			return (-1);
		create_field(obj);
	}
	else
	{
		obj->i = fscanf(fd, "%c %f %f %f %f %c%c", &obj->st, &obj->x, &obj->y, &obj->rectw, &obj->recth, &obj->stt, &obj->eol);
		if (obj->i == -1)
			return (0);
		if (obj->i != 7)
			return (-1);
		if (obj->st != 'r' && obj->st != 'R')
			return (-1);
		(obj->st == 'R') ? draw_fill(obj) : draw_empty(obj); 
	}
	return (obj->eol > 0);
}
