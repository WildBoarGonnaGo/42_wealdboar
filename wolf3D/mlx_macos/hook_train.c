/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_train.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 04:48:37 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/25 05:29:44 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars
{
	void 		*mlx;
	void		*win;
}				t_vars;

int				mlx_close(int keycode, t_vars *vars)
{
	(keycode == 65307) ? mlx_destroy_window(vars->mlx, vars->win) : printf("%d\n", keycode);
	return ((keycode == 65307) ? 0 : keycode);
}

int				main(void)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello, World!");
	if (!(mlx_key_hook(vars.win, mlx_close, &vars)))
		return (0);
	else
		mlx_loop(vars.mlx);
}
