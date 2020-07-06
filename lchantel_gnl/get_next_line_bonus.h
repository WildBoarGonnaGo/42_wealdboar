/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:54:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/06 05:15:57 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_gnl_strlen(char *str);
char	*ft_gnl_strdup(char *str, int nbytes);
char	*ft_gnl_strjoin(char *dst, char *src);
int		ft_gnl_seekchar(char *str, char c);
int		ft_gnl_read_rest(char **line, char **rest);
int		get_next_line(int fd, char **line);
int		ft_gnl_read_rest_init(char **line, char **purge_info, char *rest);

#endif
