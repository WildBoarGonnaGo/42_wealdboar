/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:04:33 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/10 18:38:34 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sh_exit(t_shell *obj)
{
	char	**tmp;
	int		res;
	int		i;

	i = -1;
	obj->len = 0;
	res = 0;
	tmp = obj->pipe_block;
	while (tmp[++obj->len])
		;
	if (obj->len >= 2)
		while (tmp[1][++i])
		{
			if (!i && tmp[1][i] == '-')
				continue ;
			res += (!(ft_isdigit(tmp[1][i])));
		}
	if (obj->len > 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(tmp[0], 2);
		ft_putstr_fd(": too many arguments\n", 2);
		res = -1;
		//obj->status[0] = 1;
	}
	else if (res)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(tmp[0], 2);
		write(2, ": ", 2);
		ft_putstr_fd(tmp[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2) ;
		res = 255;
		//obj->status[0] = 1;
	}
	else if (obj->len == 2 && !res)
	{
		res = ft_atoi(tmp[1]);
		res = res % 256 + (res < 0) * 256;
		//obj->status[0] = 1;
	}
	obj->status[0] = res;
	obj->status[1] = (!obj->err_fst) * obj->status[0] - (obj->err_fst != 0);
	//return (res);
}
