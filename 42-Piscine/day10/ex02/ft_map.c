/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:36:38 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/10 20:03:40 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		index;
	int		*map;

	index = 0;
	map = (int *)malloc(sizeof(int) * length);
	while (index < length)
	{
		map[index] = f(tab[index]);
		index++;
	}
	return (map);
}
