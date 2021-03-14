/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_find_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:03:30 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:22:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		sh_av(t_shell obj, int param,
	char spec, int st)
{
	return (obj.line[obj.roll] == spec &&
	(st & param));
}

int		sh_di(t_shell obj, int param,
	char spec, int st)
{
	return (obj.line[obj.roll] == spec &&
	!(st & param));
}

int		sh_find_elem_body(t_shell *obj, int *st)
{
	if (sh_return_if_env(*st, obj))
		obj->roll = sh_env_linefix(obj, st);
	else if (sh_return_spec_init(*st, obj))
		sh_spec_char_init(obj, st);
	else if (sh_di(*obj, ISQUOTE | ESCCHAR, '\'', *st))
		*st |= SQUOTE;
	else if (sh_di(*obj, ISQUOTE | ESCCHAR, '"', *st))
		*st |= DQUOTE;
	else if (sh_av(*obj, DQUOTE, '"', *st) && sh_di(*obj, ESCCHAR, '"', *st))
		*st &= ~DQUOTE;
	else if (sh_av(*obj, SQUOTE, '\'', *st))
		*st &= ~SQUOTE;
	else if (sh_di(*obj, SQUOTE | ESCCHAR, '\\', *st))
		*st |= ESCCHAR;
	else if ((*st & (ESCCHAR | SQUOTE)) == ESCCHAR)
		sh_escchar_case_handle(st, obj);
	else if (sh_di(*obj, SQUOTE | ESCCHAR, '$', *st))
		sh_read_env_var(st, obj);
	else if (sh_spec_char_return(*st, obj))
		return (sh_meet_spec_char(obj));
	else if (sh_return_meet_space(*st, obj))
		return (sh_meet_space_char(obj));
	else if ((*st & PARAMEXP) != PARAMEXP)
		sh_paramexp_handle(st, obj);
	return (1);
}

void	find_elem(t_shell *obj, int st)
{
	if (!obj->recycle)
		obj->recycle = ft_strdup("");
	sh_delims_override(obj);
	if (!sh_find_elem_body(obj, &st))
		return ;
	if (!(st & ~COMCHAR) && (st & COMCHAR) && obj->line[obj->roll])
		if ((obj->line[obj->roll] == '>' || obj->line[obj->roll] == '<')
		&& ft_isalnum(obj->line[obj->roll + 1]))
			return ;
	if (!(st & ENVSPACE))
		++obj->roll;
	else
		st &= ~ENVSPACE;
	find_elem(obj, st);
}
