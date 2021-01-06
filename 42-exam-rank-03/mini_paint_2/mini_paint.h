#ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_drawing
{
	int w;
	int h;
	char **arr;
}				t_drawing;

typedef struct	s_crcl
{
	char type;
	float x;
	float y;
	float r;
	char clr;
}				t_crcl;

int ft_strlen(const char *s);

#endif
