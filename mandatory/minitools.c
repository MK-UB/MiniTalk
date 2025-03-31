/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:47:34 by melayoub          #+#    #+#             */
/*   Updated: 2023/03/15 17:39:30 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	write(2, "error: ", 7);
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long long	num;

	num = (long long)n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num / 10 != 0)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar((num % 10) + '0');
}

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	sign;
// 	int	res;

// 	sign = 1;
// 	res = 0;
// 	i = 0;
// 	if(!(str[i] >= '0' && str[i] <= '9'))
// 		return(1);
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		if(!(str[i] >= '0' && str[i] <= '9'))
// 			return(1);
// 		res = res * 10 + str[i] - '0';
// 		i++;
// 	}
// 	return (res * sign);
// }

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
			i++;
	if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
