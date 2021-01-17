#include <stdio.h>
#include "~/42-wildboar-git/minishell/minishell.h"

char	*sh_strchr(const char *s, int c, size_t size)
{
	size_t		bound;
	size_t		i;

	bound = ft_strlen(s);
	i = -1;
	while (i <= bound && i < size)
		if (*(s + ++i) == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

int sh_gnl(int fd, char **line)
{
	t_gnl obj;
	obj.st = 0;
	obj.i = 0;
	if (!*line)
		*line = ft_strdup("");
	while ((obj.byte = read(fd, &obj.buf[obj.i], 1)) > 0)
	{
		if (obj.buf[obj.i] == '\n')
		{
			obj.st = 10;
			obj.buf[obj.i] = 0;
		}
		*line = addchar(*line, obj.buf[obj.i]);
		if (!obj.buf[obj.i])
			break ;
	}
	if (obj.byte <= 0)
		return (-1);
	return (obj.st);
}

int main(int argc, char **argv)
{
	int a = 0;
	char *line;
	int st;
	while (sh_gnl(0, &line))
	{
		int i = -1;
		
	}
	return (0);
}
