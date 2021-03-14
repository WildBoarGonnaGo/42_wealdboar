/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_spec_char_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:41:23 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:27:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_bitwise_or_stat(int *info, t_shell *obj, int ctrl_bit)
{
	info[1] |= ctrl_bit;
	obj->err_status *= 1;
}

void	sh_bitwise_and_stat(int *info, t_shell *obj, int ctrl_bit)
{
	info[1] &= ctrl_bit;
	obj->err_status *= 1;
}

void	sh_bitwise_or_stat_spec(int *info, t_shell *obj, int ctrl_bit)
{
	info[1] |= ctrl_bit;
	obj->spec_char = obj->line[info[0]];
}

void	sh_spec_char_handle(t_shell *obj, int ctrl_bit,
		int *info, void (*func)(int *, t_shell *, int ctrl_bit))
{
	func(info, obj, ctrl_bit);
	obj->recycle = addchar(obj->recycle, obj->line[info[0]]);
}
