/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:51:57 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 14:59:06 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
	i++;
	}
	return (0);
}

void	store_values(char **av, t_times *times)
{
	int	i;

	times->times[4] = -1;
	i = 1;
	while (av[i])
	{
		times->times[i-1] = ft_atoi(av[i]);
		i++;
	}
	printf("%ld\n", times->times[4]);
}

int	check_input2(t_times *times)
{
	int	i;
	
	i = 0;
	while (i < 6)
	{	
		if (times->times[i] > 2147483647 || times->times[i] < 0)
			return (1);
		i++;
	}
	return (0);
}
