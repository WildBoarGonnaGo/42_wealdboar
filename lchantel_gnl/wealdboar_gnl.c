#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_gnl_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (*(str + (++i)))
		;
	return (i);
}

char	*ft_gnl_strdup(char *str, int nbytes)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = (ft_gnl_strlen(str) > nbytes) ? nbytes :
	ft_gnl_strlen(str);
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	while (++i < len)
		*(res + i) = *(str + i);
	*(res + i) = 0;
	return (res);
}

char	*ft_gnl_strjoin(char *dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*join_res;
	int		cur;
	int		pos;

	cur = -1;
	pos = 0;
	if (!src)
		return (dst);
	dst_len = ft_gnl_strlen(dst);
	src_len = ft_gnl_strlen(src);
	if (!(join_res = (char *)malloc(dst_len + src_len + 1)))
		return (NULL);
	while (++cur < dst_len)
		*(join_res + cur) = *(dst + cur);
	if (dst)
		free(dst);
	while (pos < src_len)
		*(join_res + cur++) = *(src + pos++);
	*(join_res + cur) =  0;
	return (join_res);
}

int		ft_gnl_seekchar(char *str, char c)
{
	int	pos;

	pos = -1;
	if (!str)
		return (0);
	while (*(str + ++pos))
		if (*(str + pos) == c)
			return (pos);
	if (!c)
		return (pos);
	return (0);
}

int		ft_gnl_read_rest(char **line, char **rest)
{
	int		pos;
	char	*purge_info;

	purge_info = NULL;
	pos = 0;
	if ((pos = ft_gnl_seekchar(*rest, '\n')))
	{
		*line = ft_gnl_strdup(*rest, pos++);
		purge_info = *rest;
		*rest = ft_gnl_strdup(*rest + pos, ft_gnl_strlen(*rest + pos));
		if (purge_info)
			free(purge_info);
		return (1);
	}
	else
	{
		*line = ft_gnl_strdup(*rest, ft_gnl_strlen(*rest));
		if (*rest)
			free(*rest);
		*rest = NULL;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*buff_str_rest;
	char		buff_str[BUFFER_SIZE + 1];
	int			read_byte;
	int			nl_stat;

	read_byte = 0;
	if (fd < 0)
		return (-1);
	if (!(ft_gnl_read_rest(line, &buff_str_rest)))
	{!
		while ((read_byte = read(fd, buff_str, BUFFER_SIZE)) > 0)
		{
			buff_str[read_byte] = 0;
			if ((nl_stat = ft_gnl_seekchar(buff_str, '\n')) ||
			buff_str[nl_stat] == '\n')
				buff_str[nl_stat] = 0;
			*line = ft_gnl_strjoin(*line, buff_str);
			if (nl_stat || !buff_str[nl_stat])
				buff_str_rest = ft_gnl_strjoin(buff_str_rest, buff_str + ft_gnl_seekchar(buff_str, 0) + 1);
			if (nl_stat || !buff_str[nl_stat]) 
				break ;
		}
	}
	return (!(!read_byte && !buff_str_rest));
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		fprintf(stderr, "Error: not enough data.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		sleep(2);
	}
	free(line);
	return (0);
}
