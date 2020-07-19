/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:42:38 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/11 21:05:56 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*roll;
	int		size;

	roll = lst;
	size = 0;
	if (!lst)
		return (size);
	else
	{
		while (roll)
		{
			++size;
			roll = roll->next;
		}
	}
	return (size);
}
