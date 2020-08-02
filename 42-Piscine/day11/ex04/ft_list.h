/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:53:35 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/12 21:06:54 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef	struct s_list	t_list;

struct	s_list
{
	struct s_list		*next;
	void				*data;
};

t_list	*ft_create_elem(void *data);

#endif
