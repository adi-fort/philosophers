/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:51:57 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 12:01:41 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 5)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				exit (1);
		j++;
		}
	i++;
	}
}

void	store_values(char **av)
{
	times->times[0] = ft_atoi(av[1]);
	times->times[1] = ft_atoi(av[2]);
	times->times[2] = ft_atoi(av[3]);
	times->times[3] = ft_atoi(av[4]);
}

int	check_input2(char t_times *times)
{
	int	i;
	
	i = 0;
	while (i <= 4)
	{	
		if (times[i] > 2147483647 || times->time_to_die < 0)
			return (1);
		i++;
	}
	return (0);
}
