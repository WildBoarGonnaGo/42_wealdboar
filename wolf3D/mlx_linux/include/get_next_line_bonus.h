/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <wealdboar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:54:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/09/09 00:00:35 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_gnl_strlen(char *str);
char	*ft_gnl_strdup(char *str, int nbytes);
char	*ft_gnl_strjoin(char *dst, char *src);
int		ft_gnl_seekchar(char *str, char c);
int		ft_gnl_read_rest(char **line, char **rest);
int		get_next_line(int fd, char **line);
int		ft_gnl_read_rest_init(char **line, char **purge_info, char *rest);
int		ft_next_to_new_buff(char **line, char **rest);
void	ft_mem_reset(char **str);

#endif
