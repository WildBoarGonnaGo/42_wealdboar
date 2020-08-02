/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_user_lib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:25:28 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/13 18:13:50 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_USER_LIB_H
# define FT_USER_LIB_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_atoi(char *str);
void	ft_putchar_write(int fd, char c);
void	ft_putstr_ft(int fd, char *str);
void	ft_putnbr(int num);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
