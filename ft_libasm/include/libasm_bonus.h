/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:32:11 by lchantel          #+#    #+#             */
/*   Updated: 2020/11/18 00:26:43 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>

typedef struct			s_list
{
	void				*data;
	struct s_list		*next;
}						t_list;

void					ft_putchar(char c);
int						ft_strlen(char *str);
char					*ft_strcpy(char *dst, char *src);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s);
ssize_t					ft_write(int fd, const void *buf, size_t count);
ssize_t					ft_read(int fd, const void *buf, size_t count);
int						ft_atoi_base(char *str, char *base);
void					ft_list_push_front(t_list **begin_list, void *data);
int						ft_list_size(t_list *begin_list);

#endif
