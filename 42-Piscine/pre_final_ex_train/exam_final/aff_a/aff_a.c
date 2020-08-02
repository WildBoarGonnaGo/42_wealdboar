/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:42:41 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/20 13:22:28 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int index;

	index = 0;
	if (argc != 2)
		ft_putchar('a');
	else
	{
		argc = 1;
		while (argv[argc][index] != '\0')
		{
			if (argv[argc][index] == 'a')
			{
				ft_putchar('a');
				break ;
			}
			index++;	
		}
	}
	ft_putchar('\n');
	return (0);
}
