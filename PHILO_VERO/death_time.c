/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/16 18:17:39 by adi-fort         ###   ########.fr       */
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

void	ft_usleep(int time)
{
	long int	start;

	start = time_ms();
	while (time_ms() - start < time)
		usleep(150);
}

int	full(t_school *school)
{
	if (school->times_eat > 0 && school->number_philo % 2 == 0)
	{
		if (right_time(school) >= (school->times_eat * (school->sum)))
			return (1);
	}
	if (school->times_eat > 0 && school->number_philo % 2 == 1)
	{
		if (right_time(school) >= ((school->times_eat * (school->sum))
				+ school->time_to_eat / 3))
			return (2);
	}
	return (0);
}
