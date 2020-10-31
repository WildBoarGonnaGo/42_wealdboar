/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:33:18 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/11 14:02:12 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*roll;
	t_list	*kill;

	if (!*lst)
		return ;
	roll = (*lst);
	while (roll)
	{
		kill = roll;
		roll = roll->next;
		ft_lstdelone(kill, del);
	}
	*lst = NULL;
}
