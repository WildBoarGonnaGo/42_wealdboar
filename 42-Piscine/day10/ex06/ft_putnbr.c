/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:00:57 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 19:08:46 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int num)
{
	if (num == 0)
		ft_putchar('0');
	if (num < 0)
	{
		ft_putchar('-');
		ft_putnbr(-1 * num);
	}
	else if (num > 0)
	{
		if (num >= 10)
			ft_putnbr(num / 10);
		ft_putchar((num % 10) + 48);
	}
}
