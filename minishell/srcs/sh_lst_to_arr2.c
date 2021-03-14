/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lst_to_arr2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:32:32 by lchantel          #+#    #+#             */
/*   Updated: 2021/03/14 03:24:06 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**lst_to_arr2(t_list *list, int start, int size)
{
	int		info[2];
	t_list	*walker;
	char	**res;

	info[0] = -1;
	info[1] = 0;
	walker = list;
	res = (char **)malloc(sizeof(char *) * size + 1);
	while (++info[0] < start && walker)
		walker = walker->next;
	while (info[0] < start + size && walker)
	{
		res[info[1]++] = ft_strdup((char *)walker->content);
		walker = walker->next;
		++info[0];
	}
	res[info[1]] = 0x0;
	return (res);
}
