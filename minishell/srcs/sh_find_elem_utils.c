/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_find_elem_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:56:10 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:23:00 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_escchar_case_handle(int *st, t_shell *obj)
{
	*st &= ~ESCCHAR;
	if (obj->line[obj->roll] == 'n')
		obj->recycle = addchar(obj->recycle, '\n');
	else if (obj->line[obj->roll] == '$' || obj->line[obj->roll] == '\\' ||
	obj->line[obj->roll] == '"' || obj->line[obj->roll] == ' ' ||
	obj->line[obj->roll] == '\'')
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
	else if (ft_strchr("<>|;", obj->line[obj->roll]))
	{
		obj->recycle = addchar(obj->recycle, '"');
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
		obj->recycle = addchar(obj->recycle, '"');
	}
	else
	{
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll - 1]);
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
	}
}

void	sh_read_env_var(int *st, t_shell *obj)
{
	obj->readenv = (obj->roll + 1);
	*st |= PARAMEXP;
}

int		sh_meet_spec_char(t_shell *obj)
{
	--obj->roll;
	return (0);
}

int		sh_meet_space_char(t_shell *obj)
{
	obj->recycle = addchar(obj->recycle, 0);
	return (0);
}

void	sh_paramexp_handle(int *st, t_shell *obj)
{
	*st |= ((obj->line[obj->roll] == '~') * TOKTWIDDLE);
	if (*st & TOKTWIDDLE)
	{
		if (ft_strchr("\0 /.", obj->line[obj->len]))
			obj->recycle = ft_strjoin(obj->recycle,
			sh_envp_search("HOME", obj));
	}
	else
		obj->recycle = addchar(obj->recycle, obj->line[obj->roll]);
}
