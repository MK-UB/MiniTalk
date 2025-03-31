/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:43:35 by melayoub          #+#    #+#             */
/*   Updated: 2023/03/15 20:56:52 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	well_recieved(int pid)
{
	(void) pid;
	write (1, "msg recieved\n", 14);
}

void	ft_kill(char **av, int i, int j)
{
	if (av[2][j] & (1 << i))
		kill(ft_atoi(av[1]), SIGUSR1);
	else
		kill(ft_atoi(av[1]), SIGUSR2);
	if (ft_atoi(av[1]) == 1)
		ft_error("incorrect pid");
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 3)
		ft_error("arguments != 3");
	j = 0;
	signal(SIGUSR1, &well_recieved);
	while (1)
	{
		i = 0;
		while (i < 8)
		{
			ft_kill(av, i, j);
			usleep(700);
			i++;
		}
		if (av[2][j] == '\0')
			break ;
		j++;
		usleep(700);
	}
	return (0);
}
