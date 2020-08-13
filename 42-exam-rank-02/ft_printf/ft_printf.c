/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 02:16:11 by wealdboar         #+#    #+#             */
/*   Updated: 2020/08/13 05:41:26 by wealdboar        ###   ########.fr       */
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
	int		res;
	int		sp;
	char	*s_wdth;
	char	*s_prcis;
	char	*m_res;
}				objfield;

void	ft_memreset(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
	else if (mem)
	{
		free(mem);
		mem = NULL;
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
		if (*(str + pos) == c)
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
	if (!(res = (char *)malloc(size + 1)))
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
	if (!(res = (char *)malloc(size + 2)))
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

	pos = 0;
	a = 0;
	m_var = 1;
	if (!str)
		return (0);
	if (!(ft_strcmp("-2147483648", str)))
		return (INT_MIN);
	while (*(str + pos) > 9 && *(str + pos) < 13)
		++pos;
	if (ft_strchr("+-", *(str + pos)))
	{
		if (*(str + pos) == '-')
			m_var = (*str == '-') ? -1 : m_var;
		++pos;
	}
	while (ft_strchr("0123456789", *(str + pos)) && *(str + pos))
	{
		a *= 10;
		a += (*(str + pos) - 48) % 10;
		++pos;
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

void	ft_char_print(int sp, int *len, char c)
{
	if (sp)
	{
		write(1, &c, 1);
		++*len;
		ft_char_print(--sp, len, c);
	}
}

void	ft_putnbr(int a, int *size)
{
	char c;

	if (a < 0)
	{
		write(1, "-", 1);
		a *= -1;
		++*size;
	}
	if (a >= 10)
		ft_putnbr(a / 10, size);
	c = a % 10 + 48;
	++*size;
	write(1, &c, 1);
}

int		ft_integer_handle(objfield input, int data)
{
	input.res = 0;
	input.len = get_numsize(data);
	input.sp = (input.prcis > input.len) ? input.wdth - input.prcis - (data < 0)
	: input.wdth - input.len - (data < 0);
	input.sp += (!data && input.sp > 0) ? 1 : 0;
	input.prcis += (data < 0);
	if (input.sp > 0)
		ft_char_print(input.sp, &input.res, ' ');
	if (data == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (input.res + 11);
	}
	if (data < 0)
	{
		data *= -1;
		ft_char_print(1, &input.res, '-');
	}
	if ((input.prcis -= input.len) > 0/*&& data*/)
		ft_char_print(input.prcis, &input.res, '0');
	/*if (data)*/
	ft_putnbr(data, &input.res);
	return (input.res);
}

int		ft_getbitsize(unsigned int a)
{
	int size;

	size = -1;
	if (a)
		size = ft_getbitsize(a >> 1);
	return (++size);
}	

char	*ft_hex_trans(unsigned int a)
{
	char	*res;
	int		size;
	int		info[3];

	info[0] = 0;
	info[1] = 1;
	size = ft_getbitsize(a);
	info[2] = ((size % 4) > 0);
	size = ((size % 4)) ? size / 4 + 1 : size / 4;
	if (!(res = (char *)malloc(size + 1)))
		return (NULL);
	*(res + size) = 0;
	while (a)
	{
		if ((a & 1))
			info[0] += info[1];
		if (!(info[1] % 8))
		{
			*(res + --size) = "0123456789abcdef"[info[0]];
			info[0] = 0;
			info[1] = 1;
			a >>= 1;
			continue ;
		}
		info[1] *= 2;
		a >>= 1;
	}
	if (info[2])
		*(res + --size) = "0123456789abcdef"[info[0]];
	//*(res + info[2]) = 0;
	return (res);
}

int		ft_hex_handle(objfield input, unsigned int data)
{
	input.res = 0;
	if (!(input.s_wdth = ft_hex_trans(data)))
		return (-1);
	input.len = ft_strlen(input.s_wdth);
	input.res = (data) ? input.len : 0;
	input.sp = (input.wdth > input.res) ? input.wdth - input.res : 0;
	input.prcis = (input.prcis > input.len) ? input.prcis - input.len : 0;
	input.sp += (data) ? 0 : 1;
	if ((input.sp -= input.prcis)> 0)
		ft_char_print(input.sp, &input.res, ' ');
	if (input.prcis)
		ft_char_print(input.prcis, &input.res, '0');
	if (data)
		write(1, input.s_wdth, input.len);
	return (input.res);
}

int		ft_str_handle(objfield input, char *data)
{
	char	*hndl;
	char	*mem;

	mem = NULL;
	if (!data)
	{
		hndl = ft_strdup("(null)");
		mem = hndl;
	}
	else
		hndl = data;
	input.sp = 0;
	input.res = ft_strlen(hndl);
	input.pos = input.res;
	if (*input.s_prcis)
	{
		//input.wdth += (input.prcis < input.res) ? input.res - input.prcis : 0;
		input.res = (input.prcis < input.res) ? input.prcis : input.res;
		input.pos = input.res;
	}
	input.sp = input.wdth - input.res;
	if (input.sp > 0)
		ft_char_print(input.sp, &input.res, ' ');
	while (input.pos--)
		write(1, hndl++, 1);
	if (mem)
		ft_memreset((void **)&mem);
	return (input.res);
}

int		ft_printf_manager(char *str, int *len, va_list list)
{
	objfield	_proc;

	_proc.wdth = 0;
	_proc.prcis = 0;
	_proc.pos = 0;
	if (!(_proc.s_wdth = ft_strdup("")))
		return (-1);
	if (!(_proc.s_prcis = ft_strdup("")))
		return (-1);
	while (ft_strchr("0123456789", *(str + _proc.pos)))
	{
		_proc.m_res = _proc.s_wdth;
		_proc.s_wdth = ft_charjoin(_proc.s_wdth, *(str + _proc.pos++));
		ft_memreset((void **)&_proc.m_res);
	}
	if (!*_proc.s_wdth)
	{
		_proc.m_res = _proc.s_wdth;
		_proc.s_wdth = ft_charjoin(_proc.s_wdth, '0');
		ft_memreset((void **)&_proc.m_res);
	}
	if (*(str + _proc.pos) == '.')
	{
		++_proc.pos;
		while (ft_strchr("0123456789", *(str + _proc.pos)))
		{
			_proc.m_res = _proc.s_prcis;
			_proc.s_prcis = ft_charjoin(_proc.s_prcis, *(str + _proc.pos++));
			ft_memreset((void **)&_proc.m_res);
		}
		if (!*_proc.s_prcis)
		{
			_proc.m_res = _proc.s_prcis;
			_proc.s_prcis = ft_charjoin(_proc.s_prcis, '0');
			ft_memreset((void **)&_proc.m_res);
		}
	}
	_proc.wdth = ft_atoi(_proc.s_wdth);
	_proc.prcis = ft_atoi(_proc.s_prcis);
	ft_memreset((void **)&_proc.s_wdth);
	if (*(str + _proc.pos) == 'd')
		*len += ft_integer_handle(_proc, va_arg(list, int));
	if (*(str + _proc.pos) == 's')
		*len += ft_str_handle(_proc, va_arg(list, char *));
	if (*(str + _proc.pos) == 'x')
		*len += ft_hex_handle(_proc, va_arg(list, unsigned int));
	ft_memreset((void **)&_proc.s_prcis);
	return (_proc.pos);
}

int		ft_printf(const char *str, ...)
{
	va_list		_arglist;
	objfield	_info;

	_info.pos = -1;
	_info.len = 0;
	va_start(_arglist, str);
	while (*(str + ++_info.pos))
	{
		if (*(str + _info.pos) != '%')
		{
			write(1, str + _info.pos, 1);
			++_info.len;
			continue ;
		}
		++_info.pos;
		_info.pos += ft_printf_manager((char *)(str + _info.pos), &_info.len, _arglist);
	}
	va_end(_arglist);
	return (_info.len); 
}
