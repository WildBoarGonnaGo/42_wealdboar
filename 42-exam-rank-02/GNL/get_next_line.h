/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 03:42:56 by wealdboar         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/10 03:58:45 by wealdboar        ###   ########.fr       */
=======
/*   Updated: 2020/08/08 18:43:56 by lchantel         ###   ########.fr       */
>>>>>>> 61d00e1c4618fb06660e8e2cb5400b81c99fb3fa
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF
<<<<<<< HEAD
#  define BUFF 32
=======
#  define BUFF 128
>>>>>>> 61d00e1c4618fb06660e8e2cb5400b81c99fb3fa
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(char **line);
void	ft_memreset(void **mem);

#endif
