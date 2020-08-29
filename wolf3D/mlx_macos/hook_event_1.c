/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:46:01 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/29 16:24:03 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	obj_struct
{
	void	*xorg;
	void	*winx;
}				_obj;

int				close(int keycode, _obj *xserv)
{
	if (keycode == 53)
		mlx_destroy_window(xserv->xorg, xserv->winx);
	return (keycode);
}

int				main(void)
{
	_obj	hell;

	hell.xorg = mlx_init();
	hell.winx = mlx_new_window(hell.xorg, 800, 600, "hook event");
	mlx_hook(hell.winx, 2, 1L << 0, close, &hell);
	mlx_loop(hell.xorg);
	return (0);	
}
