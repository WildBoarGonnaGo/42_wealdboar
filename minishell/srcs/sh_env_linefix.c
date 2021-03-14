/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_linefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:02 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:22:03 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_env_linefix_init(t_shell *obj, char **sh_clean,
		int *st)
{
	sh_clean[0] = obj->line;
	obj->argstr = (char *)malloc(obj->roll - obj->readenv + 1);
	sh_clean[3] = obj->argstr;
	ft_strlcpy(obj->argstr, obj->line + obj->readenv,
	obj->roll - obj->readenv + 1);
	sh_clean[4] = sh_envp_search(obj->argstr, obj);
	sh_parcer_envp_fix(&sh_clean[4], obj->is_export);
	if ((*st & DQUOTE))
	{
		sh_clean[5] = sh_clean[4];
		sh_clean[4] = sh_ignore_colon(sh_clean[4]);
	}
	obj->line = (obj->readenv - 2 >= 0) ?
	ft_substr(obj->line, 0, obj->readenv - 1) : ft_strdup("");
	sh_clean[1] = obj->line;
}

int		sh_env_is_trap(t_shell *obj, int *st)
{
	*st &= ~PARAMEXP;
	obj->recycle = addchar(obj->recycle, '$');
	return (obj->roll - 1);
}

void	sh_envp_linefix_postproc(t_shell *obj, int i,
		char **sh_clean, int *st)
{
	sh_clean[2] = obj->line;
	obj->line = ft_strjoin(obj->line, sh_clean[0] + obj->roll +
	!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2));
	i = -1;
	while (++i < 5)
		sh_free_str(&sh_clean[i]);
	*st &= ~PARAMEXP;
	--obj->readenv;
	*st |= ENVSPACE;
	if (*st & DQUOTE)
	{
		while (obj->line[obj->readenv - 1] == ' ')
			--obj->readenv;
	}
	if (obj->line[obj->readenv] == ' '
	&& !ft_strncmp(obj->recycle, "", 1) &&
	!(*st & DQUOTE))
	{
		while (obj->line[obj->readenv] == ' ')
			++obj->readenv;
	}
}

int		sh_env_linefix(t_shell *obj, int *st)
{
	char	*sh_clean[6];
	int		i;

	i = -1;
	while (++i < 6)
		sh_clean[i] = 0x0;
	if (obj->line[obj->roll - 1] == '$' && (obj->line[obj->roll] == ' '
	|| obj->line[obj->roll] == '\0') && !ft_strncmp("", obj->recycle, 1))
		return (sh_env_is_trap(obj, st));
	sh_env_linefix_init(obj, sh_clean, st);
	if (!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2))
	{
		sh_clean[2] = ft_itoa(obj->status[0]);
		obj->line = ft_strjoin(obj->line, sh_clean[2]);
		sh_free_str(&sh_clean[2]);
	}
	else
		obj->line = ft_strjoin(obj->line, sh_clean[4]);
	sh_envp_linefix_postproc(obj, i, sh_clean, st);
	return (obj->readenv);
}
