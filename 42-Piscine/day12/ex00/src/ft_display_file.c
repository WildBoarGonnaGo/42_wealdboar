/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:36:14 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/13 18:24:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_user_lib.h"

#define STAT_SIZE 8192

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[STAT_SIZE + 1];
	int		ret;

	if (argc >= 3)
	{
		ft_putstr("Too many arguments\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File name missing\n");
		return (1);
	}
	ret = read(fd, buf, STAT_SIZE);
	buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
	{
		ft_putstr("close() operation failed'n");
		return (1);
	}
	return (0);
}
