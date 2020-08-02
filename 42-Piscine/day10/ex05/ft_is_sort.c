/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 11:54:25 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/14 10:45:40 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_high_sort(int *tab, int length, int (*f)(int, int))
{
	if (length == -1)
		return (1);
	if (length == 0)
		return (1);
	if (length == 1 && (f(tab[length], tab[length - 1]) > 0
				|| f(tab[length], tab[length - 1]) == 0))
		return (1);
	if (f(tab[length], tab[length - 1]) > 0 ||
			f(tab[length], tab[length - 1]) == 0)
		return (ft_high_sort(tab, length - 1, f));
	return (0);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int sort_high_state;

	sort_high_state = ft_high_sort(tab, length - 1, f);
	if (sort_high_state == 1)
		return (1);
	return (0);
}
