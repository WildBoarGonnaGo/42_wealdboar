/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcreola <lcreola@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:16:03 by lcreola           #+#    #+#             */
/*   Updated: 2020/11/16 23:38:24 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "./include/libasm.h"

int		main(void)
{
	char *str[] = {"", "abcdef", "abc;def.abcdef: abc", "a\0bc",
	"Lorem ipsum dolor sit amet, consectetur adipiscing elit.Sed in malesuada \
	purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam bibendum \
	dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. \
	Crasvolutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae\
	 rutrum nisifelis sed purus. Mauris magna ex, mollis non suscipit eu, \
	 lacinia ac turpis. Phas ellus ac tortor et lectus fermentum lobortis \
	 eu at mauris. Vestibulum sit amet posuere tortor, sit amet consequat \
	 amet.", "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f",
	 NULL, NULL};
	char *tmp = (char *)malloc(1024);
	char *tmp2;
	int	fd = 0;
	int i = 0;
	int	j = 0;
	ssize_t i1 = 0;
	ssize_t i2 = 0;
	ssize_t sum1 = 0;
	ssize_t sum2 = 0;
	int err1 = 0;
	int err2 = 0;
	printf("FT_STRLEN TEST: ");	
	while (i < 6)
	{
		printf("%s ", strlen(str[i]) == ft_strlen(str[i])? "OK": "NO");
		++i;
	}
	printf("\n");
	i = 0;
	printf("FT_STRCPY TEST: ");
	while (i < 7)
	{
		if (!str[i])
		{
			tmp2 = ft_strcpy(tmp2, str[i]);
			printf("%s ", ft_strcmp(tmp2, str[i]) == 0 ? "OK" : "NO");
		}
		else
		{
			tmp = ft_strcpy(tmp, str[i]);
			printf("%s ", ft_strcmp(tmp, str[i]) == 0 ? "OK" : "NO");
		}
		++i;
	}
	printf("\n");
	i = 0;
	j = 0;
	printf("FT_STRCMP: ");
	while (i < 7)
	{
		while (j < 6)
		{
			printf("%s ", ft_strcmp(str[i], str[j]) == strcmp(str[i], str[j]) ? "OK" : "NO");
			++j;
		}
		++i;
	}
	printf("\n");
	i = 0;
	j = 0;
	printf("FT_STRDUP TEST: ");	
	while (i < 6)
	{
		tmp2 = ft_strdup(str[i]);
		printf("%s ", ft_strcmp(tmp2, str[i]) == 0 ? "OK": "NO");
		++i;
		free(tmp2);
	}
	printf("\n");
	i = 0;
	j = 0;
	printf("FT_WRITE OUTPUT TEST: \n");
	while(i < 3)
	{
		i1 = ft_write(1, str[i], ft_strlen(str[i]));
		sum1 += i1;
		printf("\n");
		i2 = write(1, str[i], strlen(str[i]));
		sum2 +=i2;
		printf("\n");
		++i;
	}
	i1 = 0;
	i2 = 0;
	printf("FT_WRITE TEST: ");
	{
		printf("%s ", sum1 == sum2 ? "OK" : "NO");
		i1 = ft_write(1, NULL, 3);
		err1 = errno;
		i2 = write(1, NULL, 3);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_write(-1, str[1], ft_strlen(str[1]));
		err1 = errno;
		i2 = write(-1, str[1], strlen(str[1]));
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_write(42, str[1], ft_strlen(str[1]));
		err1 = errno;
		i2 = write(42, str[1], strlen(str[1]));
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");	
	}
	printf("\n");
	i1 = 0;
	i2 = 0;
	err1 = 0;
	err2 = 0;
	printf("FT_READ TEST: ");
	{
		fd = open("Makefile", O_RDONLY);
		i1 = ft_read(fd, tmp, 21);
		err1 = errno;
		i2 = read(fd, tmp, 21);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_read(42, tmp, 21);
		err1 = errno;
		i2 = read(42, tmp, 21);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_read(fd, NULL, 21);
		err1 = errno;
		i2 = read(fd, NULL, 21);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_read(fd, tmp, 0);
		err1 = errno;
		i2 = read(fd, tmp, 0);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
		i1 = ft_read(-1, tmp, 21);
		err1 = errno;
		i2 = read(-1, tmp, 21);
		err2 = errno;
		printf("%s ", i1 == i2 ? "OK" : "NO");
		printf("%s ", err1 == err2 ? "OK" : "NO");
	}
	printf("\n");
	free(tmp);
	return (0);
}
