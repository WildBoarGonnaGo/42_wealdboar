/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:45:31 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/14 10:56:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = begin_list;
	if (tmp == NULL)
		return (0);
	else
	{
		while (tmp->next != NULL)
		{
			i += 1;
			tmp = tmp->next;
		}
	}
	return (i);
}
