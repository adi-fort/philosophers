/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:51:57 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/20 10:25:45 by adi-fort         ###   ########.fr       */
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

void	store_values(int ac, char **av, t_school *school)
{
	school->times_eat = -1;
	school->number_philo = ft_atoi(av[1]);
	school->time_to_die = ft_atoi(av[2]);
	school->time_to_eat = ft_atoi(av[3]);
	school->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		school->times_eat = ft_atoi(av[5]);
	school->sum = school->time_to_eat + school->time_to_sleep;
	school->m = school ->time_to_eat * 2 ;
}

int	check_input2(t_school *school)
{
	if (school->number_philo > 2147483647 || school->number_philo < 0)
		return (1);
	else if (school->time_to_die > 2147483647 || school->time_to_die < 0)
		return (2);
	else if (school->time_to_eat > 2147483647 || school->time_to_eat < 0)
		return (3);
	else if (school->time_to_sleep > 2147483647 || school->time_to_sleep < 0)
		return (4);
	else if (school->times_eat > 2147483647 || school->times_eat < -2)
		return (5);
	return (0);
}
