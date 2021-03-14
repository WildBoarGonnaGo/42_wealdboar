/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_find_elem_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:45:38 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 04:58:39 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_spec_char_init(t_shell *obj, int *st)
{
	*st |= COMCHAR;
	obj->recycle = addchar(obj->recycle,
	obj->line[obj->roll]);
}

int		sh_return_if_env(int st, t_shell *obj)
{
	return ((((st & (SQUOTE | PARAMEXP)) == PARAMEXP) &&
	(!ft_isalnum(obj->line[obj->roll]) ||
	obj->line[obj->roll] == '?')) ||
	(((obj->line[obj->roll] == ' ' && !(st & 0b11))
	|| !obj->line[obj->roll]) && (st & PARAMEXP)));
}

int		sh_return_spec_init(int st, t_shell *obj)
{
	return (ft_strchr(";|<>", obj->line[obj->roll]) &&
	!ft_strncmp("", obj->recycle, 1)
	&& obj->line[obj->roll] && !(st & (ESCCHAR | SQUOTE)));
}

int		sh_spec_char_return(int st, t_shell *obj)
{
	return (ft_strchr(";|<>", obj->line[obj->roll]) &&
	!(st & ISQUOTE) && obj->roll && obj->line[obj->roll] != '>'
	&& obj->line[obj->roll] != '<');
}

int		sh_return_meet_space(int st, t_shell *obj)
{
	return ((obj->line[obj->roll] == ' '
	&& !(st & 0b11) && !(st & PARAMEXP))
	|| !obj->line[obj->roll]);
}
