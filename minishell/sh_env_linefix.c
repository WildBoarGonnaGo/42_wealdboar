/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_linefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:02 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/28 18:34:38 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"
#include "srcs/libft/libft.h"

int	sh_env_linefix(t_shell *obj, int *st)
{
	char	*sh_clean[5];
	int		i;

	i = -1;
	while (++i < 5)
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
	sh_clean[4] = sh_envp_search(obj->argstr, obj);
	sh_parcer_envp_fix(&sh_clean[4], obj->is_export);
	obj->line = (obj->readenv - 2 >= 0) ? 
	ft_substr(obj->line, 0, obj->readenv - 1) : ft_strdup("");
	sh_clean[1] = obj->line;
	if (!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2))
 	{
		sh_clean[2] = ft_itoa(obj->status[0]);
		obj->line = ft_strjoin(obj->line, sh_clean[2]);
		sh_free_str(&sh_clean[2]);
	}
	else
		obj->line = ft_strjoin(obj->line, sh_clean[4]);
	sh_clean[2] = obj->line;
	obj->line = ft_strjoin(obj->line, sh_clean[0] + obj->roll +
	!ft_strncmp("$?", sh_clean[0] + obj->roll - 1, 2));
	i = -1;
	while (++i < 5)
		sh_free_str(&sh_clean[i]);
	*st &= ~PARAMEXP;
	--obj->readenv; 
	while (obj->line[obj->readenv] == ' ')
		++obj->readenv;
	*st |= ENVSPACE;
	return (obj->readenv);
}
