/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo_env_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 21:12:32 by lchantel          #+#    #+#             */
/*   Updated: 2021/02/25 21:35:21 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*sh_echo_env_decode(char *str, t_shell *obj)
{
	int		pos[2];
	int		st;
	char	*res;

	pos[0] = -1;
	pos[1] = -1;
	st = 0;
	res = ft_strdup("");
	while (str[++pos[0]])
	{
		if (str[pos[0]] == '$' && !st)
		{
			st |= PARAMEXP;
			pos[1] = pos[0];
		}
		else if (st == PARAMEXP && !ft_isalnum(str[pos[0]]))
		{
			obj->argstr = (char *)malloc(pos[0] - pos[1] + 1);
			obj->clean = obj->argstr;
			ft_strlcpy(obj->argstr, str + pos[1], pos[0] - pos[1] + 1);
			res = ft_strjoin(res, sh_envp_search(obj->argstr, obj));
			st &= 0;
		}
		else if (!st)
			res = addchar(res, str[pos[0]]);
	}

}
