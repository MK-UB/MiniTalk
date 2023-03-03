#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ac == 3)
	{
		while (av[2][j])
		{
			i = 0;
			while(i < 8)
			{
				if (av[2][j] & (1 << i))
				{
					kill(atoi(av[1]), SIGUSR1);
					write(1, "1", 1);
				}
				else
				{
					kill(atoi(av[1]), SIGUSR2);
					write(1, "0", 1);
				}
				usleep(700);
				i++; 
			}
			write(1, "\n", 1);
			j++;
			usleep(700);
		}
	}
	return (0);
}