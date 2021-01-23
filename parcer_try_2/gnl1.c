/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:08:49 by student           #+#    #+#             */
/*   Updated: 2020/08/02 23:16:17 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char				*get_right(char *str, int *flag)
{
	char			*dest;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(dest = malloc(sizeof(char) * (ft_strlen(str) - i))))
	{
		*flag = -1;
		return (0);
	}
	i++;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char				*get_left(char *str, int *flag)
{
	int				i;
	char			*dest;

	i = 0;
	if (!str)
		return (0);
	while ((str[i]) && (str[i] != '\n'))
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
	{
		*flag = -1;
		return (0);
	}
	i = 0;
	while ((str[i]) && (str[i] != '\n'))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int					check_read(int fd, char **line)
{
	int				x;
	char			buf;

	x = read(fd, &buf, 0);
	if (x < 0)
		return (0);
	else if (!line || BUFFER_SIZE <= 0)
		return (0);
	else
		return (1);
}

int					check_n(char *between)
{
	int				i;

	i = 0;
	if (!between)
		return (1);
	while (between[i])
	{
		if (between[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*between;
	int				has_read;
	char			*tmp;
	int				flag;

	if ((check_read(fd, line)) == 0)
		return (-1);
	has_read = 1;
	flag = 1;
	while ((check_n(between)) && (has_read != 0))
	{
		has_read = read(fd, buff, BUFFER_SIZE);
		buff[has_read] = '\0';
		tmp = between;
		between = ft_glue(between, buff, &flag);
		free(tmp);
	}
	*line = get_left(between, &flag);
	between = get_right(between, &flag);
	if (flag == -1)
		return (-1);
	return ((has_read == 0) ? 0 : 1);
}
