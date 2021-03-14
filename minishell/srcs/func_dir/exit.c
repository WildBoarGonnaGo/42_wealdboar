/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:04:33 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 05:44:55 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cat_sh_exit1(char **tmp, int *res, int i)
{
	while (tmp[1][i])
	{
		if (!i && tmp[1][i] == '-')
			continue ;
		*res += (!(ft_isdigit(tmp[1][i])));
		++i;
	}
	i = 0;
}

void	cat_sh_exit2(char **tmp, int *res)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(tmp[0], 2);
	ft_putstr_fd(": too many arguments\n", 2);
	*res = -1;
}

void	cat_sh_exit3(char **tmp, int *res)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(tmp[0], 2);
	write(2, ": ", 2);
	ft_putstr_fd(tmp[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	*res = 255;
}

void	sh_exit(t_shell *obj)
{
	char	**tmp;
	int		res;
	int		i;

	i = 0;
	obj->len = 0;
	res = 0;
	tmp = obj->pipe_block;
	while (tmp[++obj->len])
		;
	if (obj->len >= 2)
		cat_sh_exit1(tmp, &res, i);
	if (obj->len > 2)
		cat_sh_exit2(tmp, &res);
	else if (res)
		cat_sh_exit3(tmp, &res);
	else if (obj->len == 2 && !res)
	{
		res = ft_atoi(tmp[1]);
		res = res % 256 + (res < 0) * 256;
		i = 1;
	}
	if (i)
		obj->status[0] = res;
	obj->status[1] = (!obj->err_fst) * obj->status[0] - (obj->err_fst != 0);
}
