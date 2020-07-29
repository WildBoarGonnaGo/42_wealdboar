/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_out.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:44:20 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/28 01:19:26 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OUT_H
# define FT_PRINTF_OUT_H

# include "./libft_expand.h"

# define FT_INT_MIN -2147483648
# define FT_UINT_MAX 4294967295

void	ft_print_spaces(int num_of_spaces, char space_char, int *len);
int		ft_integer_handle(char **space_info, int value, char space_char[3],
		int *len_res);
int		ft_string_handle(char **space_info, char *value, char space_char[3],
		int *len_res);
int		ft_char_handle(char **space_info, char value, char space_char[3],
		int *len_res);
int		ft_hexadec_handle(char **space_info, unsigned long long value,
		char space_char[3], int *len_res);
void	ft_special_chars(char *str_handle, char *spec_chars, int *pos);
int		ft_starfield(char **str, va_list list);
int		ft_printf_manager(char *str_handle, va_list list, int *len_res);
int		ft_printf(const char *str_arg, ...);
void	ft_putchar_fd_len(char c, int fd, int *len);
void	ft_putnbr_fd_len(int n, int fd, int *len);
void	ft_putunbr_fd_len(unsigned int num, int fd, int *len);
void	ft_putstr_fd_len(char *s, int fd, int *len);
int		ft_str_zerofic(char ***space, int num);
char	*ft_ulltoa_base(unsigned long long num, int base);
int	ft_err_handle(const char *src);

#endif
