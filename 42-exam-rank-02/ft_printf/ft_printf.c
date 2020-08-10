/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 18:08:28 by lchantel          #+#    #+#             */
/*   Updated: 2020/08/10 18:25:10 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

char			*ft_strchr(const char *str, char c)
{
	int	pos;

	pos = -1;
	while (*(str + ++pos))
		if (*(str + pos) == c)
			return (str + pos)
	return (str + pos);
}

typedef struct	width_data
{
	int	wdth;
	int	prec;
	
}				printf_obj;

int				ft_printf(const char *str, ...)
{
	va_list	arg_lst;
	int		pos[4] = {0};

	pos[0] = -1;
	while (*(str + ++(pos[0]))) 
	{
		if (*(str + pos[0]) != )
	}
}
