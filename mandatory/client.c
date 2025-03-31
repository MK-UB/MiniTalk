/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:47:41 by melayoub          #+#    #+#             */
/*   Updated: 2023/03/15 20:57:58 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
