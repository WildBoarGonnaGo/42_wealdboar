#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	char	*file;
	int		fd;
	char	*line = NULL;
	int		status;

	status = 0;
	if (argc != 2)
		return (-1);
	file = argv[1];
	fd = open(file, O_RDONLY);
	while ((status = get_next_line(fd, &line)) > 0)
	{
		printf("%d |%s\n", status, line);
		if (line)
			free(line);
	}
	ft_mem_reset(&line);
	printf("%d |%s\n", status, line);
	if (fd >= 0)
		close(fd);
	return (0);
}
