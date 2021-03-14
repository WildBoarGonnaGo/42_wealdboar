/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_err_analisys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:57:09 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:22:33 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			sh_err_analisys(char *str, t_shell *obj)
{
	int	err_fst;
	int	err_status;

	err_fst = 0;
	obj->len = ft_strlen(str);
	err_status = 0;
	obj->err_pos = SH_INT_MAX;
	obj->err_fst = 0;
	if (!ft_strncmp(str, ";;", 2))
		err_status = err_set_var(obj, str, ";;", 1);
	if (!ft_strncmp(str, "||", 2))
		err_status = err_set_var(obj, str, "||", 2);
	if (!ft_strncmp(str, "<<<<", 4))
		err_status = err_set_var(obj, str, "<<<<", 3);
	if (!ft_strncmp(str, ">>>", 3))
		err_status = err_set_var(obj, str, ">>>", 4);
	err_output(*obj);
	obj->err_status = 2 * (err_status != 0);
	return (err_status);
}
