/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/17 17:22:43 by adi-fort         ###   ########.fr       */
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
		if (right_time(school) >= (school->times_eat * (school->m)))
			return (1);
	}
	if (school->times_eat > 0 && school->number_philo % 2 == 1)
	{
		if (right_time(school) > ((school->times_eat * school->m
					+ school->sum) + school->time_to_eat))
			return (2);
	}
	return (0);
}

void	*ft_death(void *school)
{
	int			i;
	t_school	*b;

	b = (t_school *)school;
	while (1)
	{
		i = 0;
		while (i < b->number_philo)
		{
			if (b->time_to_die < right_time(b)
				- b->philosophers[i].starving_time)
			{
				pthread_mutex_lock(&b->death_m);
				b->death_counter += 1;
				pthread_mutex_unlock(&b->death_m);
				if (full(b) == 0)
					printf("%d %d is dead\n", right_time(b), i + 1);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
