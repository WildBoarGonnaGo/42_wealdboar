/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 02:46:55 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/22 11:45:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;

}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello, Wolrd!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	/*
	 * After creating an image, we can call 'mlx_get_data_addr', we pass
	 * 'bits_per_pixel', 'line_length', and 'endian' by reference. These will
	 * then be set accordingly for the *current* data address.
	 * */
	img.addr = 	mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
				&img.endian);
	my_mlx_pixel_put(&img, 300, 300, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
