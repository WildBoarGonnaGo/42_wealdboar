/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:33:00 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/13 22:52:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_user_lib.h>
#define STAT_SIZE 30736

int	main(int argc, char **argv)
{
	int		fd;
	int		rt;
	char	buf[STAT_SIZE];
	int		iter;

	iter = 0;
	while (++iter < argc)
	{
		fd = open(argv[iter], O_RDWR);
		if (ft_err_output(errno, argv[iter]) == 0)
		{
			close(fd);
			continue ;
		}
		rt = read(fd, buf, STAT_SIZE);
		ft_putstr(buf);
		buf[rt] = '\0';
		if (close(fd) == -1)
		{
			ft_putstr("close() failed\n");
			return (1);
		}
	}
	return (0);
}
