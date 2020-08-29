/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 03:42:56 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/28 02:01:37 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF
#  define BUFF 32
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(char **line);
void	ft_memreset(void **mem);

#endif
