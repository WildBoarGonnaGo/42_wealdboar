/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 00:04:37 by lchantel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/14 16:11:39 by lchantel         ###   ########.fr       */
=======
/*   Updated: 2020/05/07 00:11:40 by lchantel         ###   ########.fr       */
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
<<<<<<< HEAD
	long int	buf;

	buf = n;
	if (n < 0)
	{
		buf *= -1;
		ft_putchar_fd('-', fd);
	}
	if (buf >= 10)
		ft_putnbr_fd(buf / 10, fd);
	ft_putchar_fd(buf % 10 + 48, fd);
=======
	char	*num;

	num = ft_itoa(n);
	write(fd, num, ft_strlen(num));
	free(num);
>>>>>>> 7229591bd186ef799e60bc8a52905d08b257bb26
}
