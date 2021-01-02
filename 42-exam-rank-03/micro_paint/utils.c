/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:15:44 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/02 19:06:30 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int ft_ceil(float a)
{
	if (a - (int)a > 0)
		return ((int)a + 1);
	else
		return ((int)a);
}

int	ft_strlen(const char *str)
{
	int i;

	i = -1;
	while (*(str + ++i))
		;
	return (i);
}

void create_field(t_rect *obj)
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

void create_empty(t_rect *obj)
{
	int pos[2];

	pos[0] = ft_ceil(obj->y);
	while ((float)pos[0] <= (obj->y + obj->rh))
	{
		pos[1] = ft_ceil(obj->x);
		while ((float)pos[1] <= (obj->x + obj->rw))
		{
			obj->i = ((pos[0] == ft_ceil(obj->y) || pos[0] == (int)(obj->y + obj->rh) ||
			(pos[0] != ft_ceil(obj->y) && pos[0] != (int)(obj->y + obj->rh) &&
			(pos[1] == ft_ceil(obj->x) || pos[1] == (int)(obj->x + obj->rw)))) &&
			pos[0] >= 0 && pos[1] >= 0 && pos[0] < obj->h && pos[1] < obj->w);
			if (obj->i)
				obj->arr[pos[0]][pos[1]] = obj->stt;
			++pos[1];
		}
		++pos[0];
	}
}

void create_fill(t_rect *obj)
{
	int pos[2];

	pos[0] = ft_ceil(obj->y);
	while ((float)pos[0] <= (obj->y + obj->rh))
	{
		pos[1] = ft_ceil(obj->x);
		while ((float)pos[1] <= (obj->x + obj->rw))
		{
			obj->i = (pos[0] >= 0 && pos[1] >= 0 && pos[0] < obj->h && pos[1] < obj->w);
			if (obj->i)
				obj->arr[pos[0]][pos[1]] = obj->stt;
			++pos[1];
		}
		++pos[0];
	}
}

void print_arr(t_rect *obj)
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


int check_row(FILE *fd, t_rect *obj)
{
	int st;

	if (!obj->row)
	{
		++obj->row;
		st = fscanf(fd, "%d %d %c%c", &obj->w, &obj->h, &obj->bk, &obj->eol);
		if (st != 4)
			return (-1);
		st = ((obj->w <= 0 || obj->w > 300) || (obj->h <= 0 || obj->h > 300));
		if (st)
			return (-1);
		create_field(obj);	
	}
	else
	{
		st = fscanf(fd, "%c %f %f %f %f %c%c", &obj->st, &obj->x, 
		&obj->y, &obj->rw, &obj->rh, &obj->stt, &obj->eol);
		if (st == -1)
			return (0);
		if (st != 7 || (obj->st != 'r' && obj->st != 'R') || obj->rw <= 0 || obj->rh <= 0)
			return (-1);
		(obj->st == 'R') ? create_fill(obj) : create_empty(obj);
	}
	return (1);
}

void free_arr(t_rect *obj)
{
	obj->i = -1;
	while (++obj->i < obj->h)
	{
		free(*(obj->arr + obj->i));
		*(obj->arr + obj->i) = NULL;
	}
	free(obj->arr);
	obj->arr = NULL;
}
