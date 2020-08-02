/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:29:58 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/14 10:55:36 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;
	t_list *dest;

	dest = *begin_list;
	tmp = ft_create_elem(data);
	if (dest == NULL)
		dest = tmp;
	else
	{
		tmp->next = dest;
		dest = tmp;
	}
}
