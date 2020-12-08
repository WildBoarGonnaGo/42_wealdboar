/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:02:39 by lchantel          #+#    #+#             */
/*   Updated: 2020/12/05 11:34:28 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define DAX 0.999848
# define DAY 0.017452

typedef struct s_crcl
{
	int i;
	int row;
	int w;
	int h;
	float rx;
	float ry;
	float x;
	float y;
	char bk;
	char st;
	char stt;
	int **arr;
	char eol;
}				t_crcl;

int	ft_strlen(const char *str);
