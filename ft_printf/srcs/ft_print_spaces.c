/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_spaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:52:15 by lchantel          #+#    #+#             */
/*   Updated: 2020/07/19 16:54:27 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_out.h"

void	ft_print_spaces(int num_of_spaces, char space_char)
{
	while (num_of_spaces-- > 0)
		ft_putchar_fd(space_char, 1);
}
