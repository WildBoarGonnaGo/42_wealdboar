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
	float	x;
	float	y;
	float	rectw;
	float	recth;
	float	buf;
	char	st;
	char	stt;
	char	back;
	char	eol;
	int		**field;
}				t_rctngl;

void	create_field(t_rctngl *obj);
void	draw_empty(t_rctngl *obj);
void	draw_fill(t_rctngl *obj);
int		ft_strlen(const char *str);
int		check_row(FILE *fd, t_rctngl *obj);

# endif
