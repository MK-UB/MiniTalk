#include <signal.h>
#include <unistd.h>
#include <stdio.h>

// char ft_convert(char *c)
// {
// 	int count;
// 	int i;
// 	int temp;
// 	int j;

// 	temp = 0;
// 	count = 0;
// 	j = 0;
// 	i = 7;
// 	while (c[i] != 0 && count < 8)
// 	{
// 		temp = j;
// 		j = i * 2^count;
// 		j = j + temp;
// 		count++;
// 		i--;
// 	}
// }

void	handler_func(int sig)
{
	//printf("%d\n", sig);
	static int i;
	static char c;

	if (sig == SIGUSR1)
	{
		c = c | (1 << i);
	}	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	// ft_convert(c);
}

ft_recieved(int sig)
{
	
}

int	main()
{
	printf("this PID ---> %d\n", getpid());

	while (1)
	{
		signal(SIGUSR1, &handler_func);
		signal(SIGUSR2, &handler_func);
		pause();
	 //write(1, "\n", 1);
	 ft_recieved()
	}
	return (0);
}
