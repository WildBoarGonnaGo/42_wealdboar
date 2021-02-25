/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_linefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:02 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/25 19:11:11 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"

int	sh_env_linefix(t_shell *obj, int *st)
{
	char	*sh_clean[4];
	int		i;

	i = -1;
	while (++i < 4)
		sh_clean[i] = 0x0;
	if (obj->line[obj->roll - 1] == '$' && (obj->line[obj->roll] == ' ' 
	|| obj->line[obj->roll] == '\0') && !ft_strncmp("", obj->recycle, 1))
	{
		*st &= ~PARAMEXP;
		obj->recycle = addchar(obj->recycle, '$');
		return (obj->roll - 1);
	}
	sh_clean[0] = obj->line;
	obj->argstr = (char *)malloc(obj->roll - obj->readenv + 1);
	sh_clean[3] = obj->argstr;
	ft_strlcpy(obj->argstr, obj->line + obj->readenv, obj->roll - obj->readenv + 1);
	obj->line = (obj->readenv - 2 >= 0) ? 
	ft_substr(obj->line, 0, obj->readenv - 1) : ft_strdup("");
	sh_clean[1] = obj->line;
	if (!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2))
 	{
		sh_clean[2] = ft_itoa(obj->status[0]);
		obj->line = ft_strjoin(obj->line, sh_clean[2]);
		if (sh_clean[2])
		{
			free(sh_clean[2]);
			sh_clean[2] = NULL;
		}
	}
	else
		obj->line = ft_strjoin(obj->line, 
		sh_envp_search(obj->argstr, obj));
	sh_clean[2] = obj->line;
	obj->line = ft_strjoin(obj->line, sh_clean[0] + obj->roll +
	!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2));
	i = -1;
	while (++i < 4)
	{
		if (sh_clean[i])
		{
			free(sh_clean[i]);
			sh_clean[i] = NULL;
		}
	}
	*st &= ~PARAMEXP;
	return (obj->readenv - 2);
}
