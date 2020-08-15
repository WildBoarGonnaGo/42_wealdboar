/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 02:29:12 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/14 05:07:51 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <stdio.h>

void			ft_memreset(void **mem);
int				ft_strlen(char *str);
void			displ_bits(int val);
char			*ft_strjoin(char *src, char *dst);
char			*ft_strdup(char *str);
int				get_bitnum(int a);
char			*ft_charjoin(char *str, char c);
char			*gethex_impl(unsigned int a);
int				ft_isspace(char c);
char			ft_tolower(char c);
char			*ft_strchr(char *str, char c);
char			*ft_str_tolower(char *str);
unsigned int	ft_atou_base(char *num, int base);

#endif

