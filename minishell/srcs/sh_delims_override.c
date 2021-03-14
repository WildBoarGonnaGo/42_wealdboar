/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_delims_override.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:40:35 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:21:57 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			sh_spec_char_match_stat(t_shell *obj, char *s1, char *s2)
{
	int len;

	len = ft_strlen(s1);
	return (((!ft_strncmp(obj->line + obj->roll, s1, len) ||
	!ft_strncmp(obj->line + obj->roll, s2, len)) &&
	(obj->line[obj->roll + len] == ' ' || (obj->line[obj->roll + len]
	== '\0'))));
}

int			sh_delims_override(t_shell *obj)
{
	int st;

	st = 0;
	obj->clean = obj->recycle;
	if ((st = sh_spec_char_match_stat(obj, "\";\"", "';'")))
		obj->recycle = ft_strjoin(obj->recycle, "\";\"");
	else if ((st = sh_spec_char_match_stat(obj, "\"|\"", "'|'")))
		obj->recycle = ft_strjoin(obj->recycle, "\"|\"");
	else if ((st = sh_spec_char_match_stat(obj, "\"<\"", "'<'")))
		obj->recycle = ft_strjoin(obj->recycle, "\"<\"");
	else if ((st = sh_spec_char_match_stat(obj, "\">\"", "'>'")))
		obj->recycle = ft_strjoin(obj->recycle, "\">\"");
	else if ((st = sh_spec_char_match_stat(obj, "\">>\"", "'>>'")))
		obj->recycle = ft_strjoin(obj->recycle, "\">>\"");
	obj->roll += 3 * (st != 0) + ((!ft_strncmp(obj->line + obj->roll,
	"\">>\"", 4) || !ft_strncmp(obj->line + obj->roll, "'>>'", 4))
	&& (obj->line[obj->roll + 4] == ' ' || (obj->line[obj->roll + 4]
	== '\0')));
	obj->clean = (st) ? obj->clean : 0x0;
	sh_free_str((char **)&obj->clean);
	return (st);
}
