/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:47:51 by melayoub          #+#    #+#             */
/*   Updated: 2023/03/15 17:46:43 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handler_func(int sig, siginfo_t *hold, void *dc)
{
	static int	n = 0;
	static char	c = 0;
	static int	pid;

	(void) dc;
	if (hold->si_pid != pid)
	{
		pid = hold->si_pid;
		c = 0;
		n = 0;
	}
	if (sig == SIGUSR1)
	{
		c = c | (1 << n);
	}
	n++;
	if (n == 8)
	{
		ft_putchar(c);
		n = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_sigaction = &handler_func;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	write(1, "PID: --> ", 9);
	ft_putnbr(pid);
	write (1, "\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
