/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:02:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/07 11:31:13 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int ft_strlen(const char *str)
{
	int len;

	len = -1;
	while (str(++len))
		;
	return (len);
}

int	ft_ceil(float a)
{
	if ((a - (int)a) > 0)
		return ((int)a + 1);
	return ((int)a);
}

void create_arr(t_drawing *obj)
{
	int pos[2];

	pos[0] = -1;
	obj->i = -1;
	obj->arr = (int **)calloc(obj->h, sizeof(int *));
	while (++obj->i < obj->h)
		obj->arr[obj->i] = (int *)calloc(obj->w, sizeof(int));
	while (++pos[0] < obj->h)
	{
		pos[1] = -1;
		while (++pos[1] < obj->w)
			obj->arr[pos[0]][pos[1]] = obj->bk;
	}
}


int get_field(FILE *fd, t_drawing *obj)
{
	int ret;
	int i;
	char back;
	char eol;

	if (!(ret = fscanf(fd, "%d %d %c%c", &obj->w, &obj->h, &back, &eol)))
		return (1);
	if (obj->w <= 0 || obj->w > 300 && obj->h <= 0 && obj->h > 300)
		return (1);
	if (!create_arr(t_drawing))
		return (1);
	return (0);
}
