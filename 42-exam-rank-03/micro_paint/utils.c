#include "micro_paint.h"

int		ft_ceil(float a)
{
	if ((a - (int)a) > 0)
		return ((int)(a + 1));
	else
		return ((int)a);
}

int		ft_strlen(const char *str)
{
	int	len;

	len = -1;
	while (*(str + ++len))
		;
	return (len);
}

void	create_field(t_rctngl *obj)
{
	int	pos[2];

	pos[0] = -1;
	obj->i = -1;
	obj->field = (int **)calloc(obj->height, sizeof(int *));
	while (++obj->i < obj->width)
		*(obj->field + obj->i) = (int *)calloc(obj->width, sizeof(int));
	pos[0] = -1;
	while (++pos[0] < obj->height)
	{
		pos[1] = -1;
		while (++pos[1] < obj->width)
			obj->field[pos[0]][pos[1]] = obj->back;
	}
}

void	draw_fill(t_rctngl *obj)
{
	float	pos[2];

	pos[0] = (obj->y - 1);
	while (++pos[0] < (obj->y + obj->recth))
	{
		pos[1] = (obj->x - 1);
		while (++pos[1] < (obj->x + obj->rectw))
			obj->field[ft_ceil(pos[0])][ft_ceil(pos[1])] = obj->stt;
	}
}

void	draw_empty(t_rctngl *obj)
{
	float	pos[2];

	pos[0] = obj->y - 1;
	while (++pos[0] < obj->y + obj->recth)
	{
		pos[1] = (obj->x - 1);
		while (++pos[1] < (obj->x + obj->rectw))
			if ((pos[0] == obj->y || pos[0] == obj->y + obj->recth - 1) ||
				((pos[0] != obj->y && pos[0] != obj->y + obj->recth - 1) && 
				 (pos[1] == obj->x || pos[1] == obj->x + obj->rectw - 1)))
			obj->field[ft_ceil(pos[0])][ft_ceil(pos[1])] = obj->stt;
	}
}
