#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_error(char *str)
{
	write (2, "error: ", 7);
	write (2, str, ft_strlen(str));
	exit(1);
}

int	main(int ac, char **av)
{
	int i;
	int j;
	int index;

	if (ac == 3)
	{
		j = 0;
		while (av[2][j])
		{
			i = 0;
			while(i < 8)
			{
				if (av[2][j] & (1 << i))
					kill(atoi(av[1]), SIGUSR1);
				else
					kill(atoi(av[1]), SIGUSR2);
				usleep(700);
				i++; 
			}
			write(1, "\n", 1);
			j++;
			usleep(700);
		}
	}
	else
		ft_error("arguments != 3");
	return (0);
}