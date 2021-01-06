/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/01/05 12:45:20 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./srcs/libft/libft.h"

typedef struct	s_gnl
{
	int 		st;
	char		buf[2048];
	int			byte;
	int			i;
}				t_gnl;

int sh_gnl(int fd, char **line);

#endif
