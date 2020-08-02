/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:26:53 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/14 10:41:04 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_count_if(char **tab, int (*f)(char*))
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (tab[index][0] != 0)
	{
		if (f(tab[index]) == 1)
			count++;
		index++;
	}
	return (0);
}
