/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:02:39 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/02 18:34:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define DAX 0.9999904807207345
# define DAY 0.004363309284746571
# define DAXE 0.9998476951563913
# define DAYE 0.01745240643728351

typedef struct s_crcl
{
	int i;
	int row;
	int w;
	int h;
	double rx;
	double ry;
	double x;
	double y;
	char bk;
	char st;
	char stt;
	int **arr;
	char eol;
}				t_crcl;

int		ft_strlen(const char *str);
void	print_arr(t_crcl *obj);
void	free_arr(t_crcl *obj);
int		check_row(FILE *fd, t_crcl *obj);

#endif
