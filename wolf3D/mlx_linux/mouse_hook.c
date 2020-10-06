/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 05:32:08 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/06 20:59:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

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
	/*mlx_destroy_window(obj->xorg, obj->winx);
	exit(0);*/
}

int				get_key(int	key)
{
	return (printf("key code: %d\n", key));
}

int				enter_window()
{
	return(printf("Enetered window\n"));
}

int				leave_window()
{
	return(printf("Leave Window\n"));
}

int				close_window()
{
	//mlx_destroy_window(obj->xorg, obj->winx);
	errno = (errno == 11) ? 0 : errno;
	printf("Window is closed\n");
	exit(errno);
}

int				main(void)
{
	_glxinfo	obj;
	obj.xorg = mlx_init();
	obj.winx = mlx_new_window(obj.xorg, 800, 600, "Mouse hook");
	mlx_mouse_hook(obj.winx, get_mpos, &obj);
	mlx_hook(obj.winx, 7, 1L<<4, enter_window, &obj);
	mlx_hook(obj.winx, 8, 1L<<5, leave_window, &obj);	
	mlx_key_hook(obj.winx, get_key, &obj);
	mlx_hook(obj.winx, 17, 1Lu<<17u, close_window, &obj);
	mlx_loop(obj.xorg);	
}

