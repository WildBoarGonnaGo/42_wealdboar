/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:43:04 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/11 21:04:31 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*roll;

	roll = lst;
	if (!lst)
		return (NULL);
	else
	{
		while (roll->next)
			roll = roll->next;
	}
	return (roll);
}
