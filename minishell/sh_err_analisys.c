/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_err_analisys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:57:09 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/07 02:27:25 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int			sh_err_analisys(char *str, t_shell *obj)
{
	int	err_fst;
	int	err_status;
	int	len;

	err_fst = 0;
	obj->len = ft_strlen(str);
	err_status = 0;
	obj->err_pos = SH_INT_MAX;
	obj->err_fst = 0;
	if (ft_strnstr(obj->line, ";;", obj->len) != NULL)
		err_status = err_set_var(obj, str, ";;", 1);
	if (ft_strnstr(obj->line, "||", obj->len) != NULL)
		err_status = err_set_var(obj, str, "||", 2);
	if (!ft_strncmp("<<<", obj->line, 4) || !ft_strncmp("<<", obj->line, 3) ||
	!ft_strncmp(">>", obj->line, 3) || !ft_strncmp(">", obj->line, 2) || 
	!ft_strncmp("<", obj->line, 2))
	{
		obj->err_fst = 5;
		err_status = 1;
	}
	if (ft_strnstr(obj->line, "<<<<", obj->len) != NULL)
		err_status = err_set_var(obj, str, "<<<<", 3);
	if (ft_strnstr(obj->line, ">>>", obj->len) != NULL)
		err_status = err_set_var(obj, str, ">>>", 4);
	err_output(*obj);
	return (err_status);
}

