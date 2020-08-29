/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 15:04:11 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/29 16:23:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	info
{
	void		*xorg;
	void		*winx;
}				_obj;

int				hello(void)
{

	printf("Hello!\n");
	return (0);
}

int				bye(void)
{
	printf("Bye!\n");
	return (0);
}

int				main(void)
{
	_obj		obj;

	obj.xorg = mlx_init();
	obj.winx = mlx_new_window(obj.xorg, 1024, 768, "example");
	mlx_hook(obj.winx, 4, (1L << 2), hello, &obj);
	mlx_hook(obj.winx, 5, (1L << 3), bye, &obj);
	mlx_loop(obj.xorg);
}
