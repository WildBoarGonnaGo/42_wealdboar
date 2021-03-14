/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_envp_fix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:55:11 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:26:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		sh_envp_squote_off(int res, char **str, int *st)
{
	if ((*st & SQUOTE))
		*str = addchar(*str, '\"');
	*st &= ~SQUOTE;
	return (res);
}

void	sh_envp_squote_on(int *st, char **str)
{
	if (!*st)
	{
		*str = addchar(*str, '\"');
		*st |= SQUOTE;
	}
}

void	sh_envp_fix_body(char **res, int *info,
		char **str, int st)
{
	if ((*(*str + info[0])) == ' ' && !st)
		info[1] &= sh_envp_squote_off(~PARAMEXP, res, &info[1]);
	else if (ft_strchr("\"'$\\", *(*str + info[0])))
		*res = addchar(*res, '\\');
	else if (!(info[1] & PARAMEXP) && !st)
		sh_envp_squote_on(&info[1], res);
	*res = addchar(*res, *(*str + info[0]));
}

void	sh_parcer_envp_fix(char **str, int st)
{
	char	*clean[2];
	int		info[2];
	char	*res;

	clean[0] = *str;
	info[0] = -1;
	info[1] = 0;
	clean[1] = 0;
	res = ft_strdup("");
	while (*(*str + ++info[0]))
		sh_envp_fix_body(&res, info, str, st);
	if (!info[0])
		res = addchar(res, '\"');
	if (!(info[1] & PARAMEXP) && !st &&
	(!info[0] || *(*str + info[0] - 1) != ' '))
		res = addchar(res, '\"');
	if (!ft_strncmp(res, "\"\"", 3))
	{
		clean[1] = res;
		res = ft_strdup("");
		sh_free_str(&clean[1]);
	}
	*str = res;
	sh_free_str(&clean[0]);
}
