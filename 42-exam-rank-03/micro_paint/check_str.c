#include "micro_paint.h"

int	check_row(FILE *fd, t_rctngl *obj)
{
	char	buf[1024];
	char	st;

	obj->i = 0;
	if (!obj->row)
	{
		++obj->row;
		obj->i = fscanf(fd, "%d %d %c", &obj->width, &obj->height, &obj->back);
		if (obj->i != 3)
			return (-1);
		obj->i = ((obj->width < 0 && obj->width > 300) ||
		(obj->height < 0 && obj->height > 300));
		if (obj->i)
			return (-1);
		create_field(obj);
	}
	else
	{
		obj->i = fscanf(fd, "%c %f %f %c", &st, obj->rectw, obj->recth,  );
		if (obj->i != 4)
			return (-1);
	}
}
