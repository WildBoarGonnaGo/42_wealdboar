/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:02:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/01/07 01:38:40 by lchantel         ###   ########.fr       */
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

int get_field(FILE *fd, t_drawing *obj)
{
	int ret;
	char *tmp;
	int i;
	char back;

	ret = fscanf(fd, "%d %d")
}
