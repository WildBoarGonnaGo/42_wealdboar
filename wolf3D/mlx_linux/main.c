/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 03:05:23 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/02 05:59:29 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geoms.h"
#include "../colors.h"

void	scale_frog(img_info *img, double scale);

int	main(void)
{
	void		*xorg;
	void		*winx;
	//_ellipse	fig;
	img_info	fig_info;
	//bitmap		color;

	xorg = mlx_init();
	winx = mlx_new_window(xorg, 800, 600, "ellipse test");
	/*ellipse_init(&fig, 0, 360.0, 100, 175, 400, 300, 45);
	set_color(&color, 159, 109, 254, 84);
	fig_info.img = mlx_new_image(xorg, 800, 600);
	std_ellipse_arc(&fig_info, fig, color._clrfull);*/
	fig_info.img = mlx_new_image(xorg, 800, 600);
	scale_frog(&fig_info, 8);
	mlx_put_image_to_window(xorg, winx, fig_info.img, 0, 0);
	mlx_loop(xorg);
}
