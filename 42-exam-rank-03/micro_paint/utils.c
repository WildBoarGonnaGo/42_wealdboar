#include "micro_paint.h"

void	create_field(t_rctngl *obj)
{
	obj->i = -1;
	obj->field = (int **)calloc(obj->height, sizeof(int *));
	while (++obj->i < obj->width)
		*(obj->field + obj->i) = (int *)calloc(obj->width, sizeof(int));
}
