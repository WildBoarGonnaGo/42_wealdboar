/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_expand.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:30:09 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 23:27:19 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_EXPAND_H
# define LIBFT_EXPAND_H

# include <stdarg.h>
# include "./libft.h"

char	*ft_itoa_base(unsigned int num, int base);
void	ft_var_putstr_fd(int args, int fd, ...);
char 	*ft_utoa(unsigned int n);
void	ft_mem_reset(void **mem_target);
void	ft_mem_reset_arg(int num, ...);
void	ft_putunbr_fd(unsigned int num, int fd);
char	*ft_str_toupper(char *str);
char	*ft_charjoin(char *str, char c);

#endif
