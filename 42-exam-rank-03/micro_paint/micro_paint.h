#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef	struct	s_rctngl
{
	int		width;
	int		height;
	int		i;
	int		row;
	int		fd;
	float	rectw;
	float	recth;
	float	buf;
	char	back;
	char	bound;
	char	fill;
	int		**field;
}				t_rctngl;

void	create_field(t_rctngl *obj);

# endif
