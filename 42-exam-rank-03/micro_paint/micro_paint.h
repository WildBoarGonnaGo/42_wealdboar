/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:20:21 by lchantel          #+#    #+#             */
/*   Updated: 2020/12/04 23:45:42 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_rect
{
	int		row;
	int 	i;
	int		w;
	int		h;
	float	x;
	float	y;
	float	rw;
	float	rh;
	char	bk;
	char	st;
	char	stt;
	int		**arr;
	char	eol;
}				t_rect;

int				ft_strlen(const char *str);
int				check_row(FILE *fd, t_rect *obj);
void			print_arr(t_rect *obj);
void			free_arr(t_rect *obj);

#endif
