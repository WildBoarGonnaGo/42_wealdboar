/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:30:31 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/13 17:55:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
=======
/*   Updated: 2020/05/12 00:09:28 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*relst;
	t_list	*marine;

	if (!lst || !f)
		return (NULL);
	if (!(marine = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	relst = marine;
	lst = lst->next;
	while (lst)
	{
		if (!(marine = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&relst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&relst, marine);
	}
	return (relst);
}
