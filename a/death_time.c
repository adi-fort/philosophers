/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/20 12:43:14 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_ms(void)
{
	struct timeval	tv_u;

	gettimeofday(&tv_u, 0);
	return ((tv_u.tv_sec * 1000) + (tv_u.tv_usec / 1000));
}

int	right_time(t_school *school)
{
	return (time_ms() - school->starting_time);
}

int	oracle(t_school *school)
{
	if (school->times_eat > 0
		&& (school->timing > school->times_eat * school->time_to_die))
		return (0);
	if (school->time_to_die < school->sum
		|| school->time_to_die < school->m)
		return (0);
	return (1);
}
