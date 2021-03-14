/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_list_semicol_fix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:40:28 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:24:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sh_list_semicol_fix(t_shell *obj)
{
	char	*clean;
	t_list	*roll;

	roll = obj->lst_start;
	while (roll)
	{
		if (!ft_strncmp((char *)roll->content, "\";\"", 4))
		{
			clean = (char *)roll->content;
			roll->content = ft_strdup(";");
			sh_free_str(&clean);
		}
		roll = roll->next;
	}
}
