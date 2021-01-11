#include "../srcs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = { "/bin/cat" };
	char *arg[] = { argv[0], "file.txt", NULL};
	char *shit[] = { NULL, NULL };
	execve(cmd[0], arg, NULL);
	return (0);
}
