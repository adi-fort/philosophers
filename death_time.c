/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/28 12:58:08 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_ms(void)
{
	struct timeval	tv_u;

	gettimeofday(&tv_u, 0);
	return ((tv_u.tv_sec * 1000) + (tv_u.tv_usec / 1000));
}

int	right_time(t_school *school)
{
	return (time_ms() - school->starting_time);
}

int	full(t_school *school)
{
	if (school->times_eat > 0)
	{
	if (right_time(school) >= school->times_eat * (school->time_to_eat + school->time_to_sleep))
		return (1);
	}
	 return (0);
}

int	death(t_philo *philo)
{ 
	if (philo->back->time_to_die < right_time(philo->back) -  philo->starving_time)
	{
		printf("%d %d is dead\n", right_time(philo->back), philo->philo_id);
		return (1);
	}
	return (0);
}
