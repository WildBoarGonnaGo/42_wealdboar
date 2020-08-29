/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 05:32:08 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/26 03:29:24 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	mlx_data
{
	void	*xorg;
	void	*winx;
}				_glxinfo;

/*typedef	strcut	mouse_param
{
	int	x;
	int	y;
	int button;
}				_mouse;*/

int				get_mpos(int button, int x, int y/*, _glxinfo *obj*/)
{
	return (printf("mouse_pos: x = %d, y = %d, btn_code = %d\n", x, y, button));
}

int				main(void)
{
	_glxinfo	obj;
	
	obj.xorg = mlx_init();
	obj.winx = mlx_new_window(obj.xorg, 800, 600, "Mouse hook");
	mlx_mouse_hook(obj.winx, get_mpos, &obj);
	mlx_loop(obj.xorg);
}

