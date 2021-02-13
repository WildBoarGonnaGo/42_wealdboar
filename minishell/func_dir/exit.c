/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:04:33 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/13 20:07:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int sh_exit(t_shell *obj)
{
	char	**tmp;
	int		res;
	int		i;

	i = -1;
	obj->len = 0;
	res = 0;
	obj->status[0] = 0;
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
		write(2, "minishell: ", ft_strlen("minishell: "));
		write(2, tmp[0], ft_strlen(tmp[0]));
		write(2, ": ", 2);
		write(2, "too many arguments\n",
		ft_strlen("too many arguments\n"));
		res = -1;
		obj->status[0] = 1;
	}
	else if (res)
	{
		write(2, "minishell: ", ft_strlen("minishell: "));
		write(2, tmp[0], ft_strlen(tmp[0]));
		write(2, ": ", 2);
		write(2, tmp[1], ft_strlen(tmp[1]));
		write(2, ": ", 2);
		write(2, "numeric argument required\n",
		ft_strlen("numeric argument required\n"));
		res = 255;
		obj->status[0] = 1;
	}
	else if (obj->len == 2 && !res)
	{
		res = ft_atoi(tmp[1]);
		res = res % 256 + (res < 0) * 256;
		obj->status[0] = 1;
	}
	return (res);
}
