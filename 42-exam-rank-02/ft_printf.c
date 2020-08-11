/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 02:16:11 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/11 05:45:54 by wealdboar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	frmtfield
{
	int 	wdth;
	int		prcis;
	int		len;
	int		pos;
	char	*s_wdth;
	char	*s_prcis;
}				objfield;

void	ft_memreset(void **mem)
{
	if (*mem)
	{
		free(*mem)
		*mem = NULL;
	}
}

int		ft_strlen(char *str)
{
	int	size;

	size = -1;
	while(*(str + ++size))
		;
	return (size);
}

char	*ft_strchr(char *str, char c)
{
	int	pos;

	pos = -1;
	if (!str)
		return (NULL);
	while (*(str + ++pos))
		if (*(str + pos) == 'c')
			return (str + pos);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		size;
	int		pos;

	pos = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 2)));
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = *(str + pos);
	*(res + pos) = 0;
	return (res);
}

char	*ft_charjoin(char *str, char c)
{
	char	*res;
	int		size;
	int		pos;

	pos = -1;
	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char *)malloc(size + 2)));
		return (NULL);
	while (*(str + ++pos))
		*(res + pos) = *(str + pos);
	*(res + pos++) = c;
	*(res + pos) = 0;
	return (res);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*(s1++) != *s2)
			return (*(--s1) - *s2);
		if (!*(s2++))
			return (0);
	}
	return (0);
}

int		ft_atoi(char *str)
{
	int		a;
	int		m_var;
	int		pos;

	if (!(ft_strcmp("-2147483648", str)))
		return (INT_MIN);
	m_var = (*str == '-') ? -1 : 1;
	pos = ft_strlen(str);
	while (--pos >= 0)
	{
		a *= 10;
		a += *(str + pos) % 10 + 48;
	}
	return (a * m_var);
}

int		get_numsize(int a)
{
	int	size;

	size = 0;
	if (a == -2147483648)
		return (11);
	if (a < 0)
	{
		a *= -1;
		++size;
	}
	while (a /= 10)
		++size;
	return (++size);
}	

void	ft_sp_print()

int		ft_integer_handle(objfield input, int data)
{
	int	res;
	int	sp;
	int	len;

	res = 0;
	len = get_numsize(data);
	sp = (input.prcis > len) ? input.width - input.prcis : input.width - len;
	if (sp > 0)
		while (sp--)
		{
			write(1, ' ', 1)
		}
	if (data == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	
}

int		ft_printf_manager(char *str, int *len)
{
	objfield	_proc;

	_proc.width = 0;
	_proc.prec = 0;
	_proc.pos = -1;
	if (!(_proc.s_width = ft_strdup("")))
		return (-1);
	if (!(_proc.s_prcis = ft_strdup("")))
		return (-1);
	while (ft_strchr("0123456789", *(str + ++_proc.pos)))
		ft_charjoin(_proc.s_width, *(str + _proc.pos));
	if (!_proc.(*s_width))
		ft_charjoin(_proc.s_width, '0');
	if (*(str + _proc.pos) == '.')
		while (ft_strchr("0123456789", *(str + ++_proc.pos)))
			ft_charjoin(_proc.s_prcis, *(str + _proc.pos));
	if (!_proc.(*s_prcis))
		ft_charjoin(_proc.s_prcis, '0');
	_proc.width = ft_atoi(_proc.s_width);
	_proc.prcis = ft_atoi(_proc.s_prcis);
	if (_proc.(*s_width) == 'd')
	
}

int	ft_printf(const char *str, ...)
{
	va_list		_arglist;
	objfield	_info;

	_info.pos = -1;
	_info.len = 0;
	va_start(_arglist, str)
	while (*(str + ++_info.pos))
	{
		if (*(str + _info.pos) != '%')
		{
			write(1, str + _info.pos++, 1)
			++_info.len;
			continue ;
		}
		
	}
}
