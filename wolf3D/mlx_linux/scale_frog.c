/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_frog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 03:37:03 by wealdboar         #+#    #+#             */
/*   Updated: 2020/09/03 00:51:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	void			ellipse_init(_ellipse *init, double alpha_strt, double alpha_arc,
					double l_radius, double b_radius, double xc, double yc, double slope);
	void			std_ellipse_arc(img_info *ellipse, _ellipse trgt, unsigned int color);
	void			arc_init(_arc *init, double xc, double yc, double radius,
					double alpha_strt, double alpha_end);
	void			arc_output(img_info *arc, _arc trgt, unsigned int color);

 * */

#include <geoms.h>
#include "../colors.h"

void	scale_frog(img_info *img, double scale)
{
	bitmap		clr_tool;
	_ellipse	el_tool;
	_arc		arc_tool;
	double		frog_pos[2] = {400, 300};
 
	set_color(&clr_tool, 159, 109, 254, 84);
	ellipse_init	(&el_tool, -53.902, 107.804, scale * 7.271, scale * 10.388, 
					frog_pos[0] + scale * 31.355, frog_pos[1] + 0, 0);
	std_ellipse_arc	(img, el_tool, clr_tool._clrfull);
	ellipse_init	(&el_tool, -64.657, 134.397, scale * 5.377, scale * 7.191, 
					frog_pos[0] + scale * 30.475, frog_pos[1] + scale * 7.554, 51.995);
	std_ellipse_arc	(img, el_tool, clr_tool._clrfull);
	ellipse_init	(&el_tool, -64.74, 134.397, scale * 5.377, scale * 7.191, 
					frog_pos[0] + scale * 30.475, frog_pos[1] - scale * 7.554, -51.995);
	std_ellipse_arc	(img, el_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 31.926, frog_pos[1] + scale * 9.296, scale * 4.059, -19.001, 155.505);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 31.926, frog_pos[1] - scale * 9.296, scale * 4.059, -136.504, 155.505);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 33.269, frog_pos[1] + scale * 11.51, scale * 1.612, -242.102, 242.286);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 33.269, frog_pos[1] - scale * 11.51, scale * 1.612, -0.185, 242.286);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 31.591, frog_pos[1] + scale * 8.743, scale * 4.296, 40.011, 37.506);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 31.591, frog_pos[1] - scale * 8.743, scale * 4.296, -77.5175, 37.506);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 33.353, frog_pos[1] + scale * 11.649, scale * 4.395, 174.265, 128.999);
	arc_output		(img, arc_tool, clr_tool._clrfull);
	arc_init		(&arc_tool, frog_pos[0] + scale * 33.353, frog_pos[1] - scale * 11.649, scale * 4.395, -303.264, 128.999);
	arc_output		(img, arc_tool, clr_tool._clrfull);
}
