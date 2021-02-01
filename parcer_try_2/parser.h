/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 23:13:04 by student           #+#    #+#             */
/*   Updated: 2020/08/02 23:13:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int					get_next_line(int fd, char **line);
int					check_n(char *between);
int					ft_strlen(char *str);
char                **create_words(char *s);
int					check_read(int fd, char **line);
char				*get_left(char *between, int *flag);
char				*get_right(char *between, int *flag);
char				*ft_glue(char *between, char *buff, int *flag);
char				**ft_split(char const *s, char c);
int                 ft_isspec(char c);
char                *ft_strjoinc(char *s, char c);
int                 ft_isalpha(int c);
void                *memrealloc(void *mem, int oldsize, int addbyte);

#endif
