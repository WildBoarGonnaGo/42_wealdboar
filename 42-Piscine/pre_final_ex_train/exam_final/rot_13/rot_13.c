#include <unistd.h>

int		main(int argc, char **argv)
{
	int a;

	a = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		while (argv[1][a])
		{
			if (argv[1][a] >= 'A' && argv[1][a] <= 'Z')
			{
				argv[1][a] += 13;
				if (argv[1][a] > 'Z')
					argv[1][a] -= 26;
			}
			else if(argv[1][a] >= 'a' && argv[1][a] <= 'z')
			{
				argv[1][a] -= 19;
				if (argv[1][a] > 'Z')
					argv[1][a] -= 26;
				argv[1][a] += 32;
			}
			write(1, &argv[1][a], 1);
			a++;
		}
		write(1, "\n", 1);
		return (0);
	}
}
