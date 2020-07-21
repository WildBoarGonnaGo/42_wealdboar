/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_out.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:44:20 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/20 23:22:29 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OUT_H
# define FT_PRINTF_OUT_H

# include "./libft_expand.h"

void	ft_print_spaces(int num_of_spaces, char space_char);
int		ft_integer_handle(char **space_info, int value, char space_char[3]);
int		ft_string_handle(char **space_info, char *value, char space_char[3]);
int		ft_char_handle(char **space_info, char value, char space_char[3]);
int		ft_hexadec_handle(char **space_info, int value, char space_char[3]);
void	ft_special_chars(char *str_handle, char *spec_chars, int *pos);
int		ft_starfield(char **str, va_list list);
int		ft_printf_manager(char *str_handle, va_list list);
int		ft_printf(const char *strArg, ...);

#endif
