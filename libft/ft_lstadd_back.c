/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:44:06 by lchantel          #+#    #+#             */
/*   Updated: 2020/05/11 11:12:37 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*roll;

	if (!*lst)
		*lst = new;
	else
	{
		roll = *lst;
		while (roll->next)
			roll = roll->next;
		roll->next = new;
	}
}
