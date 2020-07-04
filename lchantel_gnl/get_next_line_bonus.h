/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:54:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/04 12:57:31 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

int		ft_gnl_strlen(char *str);
char	*ft_gnl_strdup(char *str, int nbytes);
char	*ft_gnl_strjoin(char *dst, char *src);
int		ft_gnl_seekchar(char *str, char c);
int		ft_gnl_read_rest(char **line, char **rest);

#endif
