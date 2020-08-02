#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "list.h"
#include <unistd.h>

# define BUF_SIZE 10

int	main(void)
{
	int		fd;
	int 	ret;
	char	buf[BUF_SIZE + 1];

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	//ft_putnbr (fd);
	//ft_putchar('\n');
	//ft_putstr_fd(fd, "\nTsugi wa Jotaro! Kisama da!");
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(" - ");
		ft_putstr(buf);
		ft_putchar('\n');
		lseek(fd, -10, SEEK_END);
	}
	buf[ret] = '\0';
	ft_putnbr(ret);
	ft_putchar('\n');
	ft_putstr(buf);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}
