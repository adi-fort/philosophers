/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/14 12:49:51 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo)
{
	t_philo 			*aristotele;

	aristotele = (t_philo *)philo;
	pthread_mutex_lock(&aristotele->fork);
	printf("%d has taken a fork\n", aristotele->philo_id);
	
	printf("%d\n", aristotele->next_philo_id);
	
	pthread_mutex_lock(&aristotele->school->philosophers[aristotele->next_philo_id].fork);
	printf("%d has taken a fork\n", aristotele->philo_id);
	printf("%d is eating\n", aristotele->philo_id);
	usleep(aristotele->school->time_to_eat);
	pthread_mutex_unlock(&aristotele->fork);
	printf("%d\n", aristotele->next_philo_id);
	pthread_mutex_unlock(&aristotele->school->philosophers[aristotele->next_philo_id].fork);
	
	printf("%d is thinking\n", aristotele->philo_id);
	printf("%d is sleepng\n", aristotele->philo_id);
	return (0);
}

void	thread_create(t_school *school)
{
	int i;

	i = 0;
	school->philosophers = (t_philo *)malloc(sizeof(t_philo) * school->number_philo);
	while (i < school->number_philo)
	{
		school->philosophers[i].philo_id = i + 1;
		school->philosophers[i].next_philo_id = i + 1;
		if (i + 1 == school->number_philo)
			school->philosophers[i].next_philo_id = 0;
		pthread_create(&school->philosophers[i].philo, NULL, &ft_routine, (void *)&school->philosophers[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_school school;
	int	i;

	if ((ac == 5 || ac == 6) && !check_input(av))
		store_values(ac, av, &school);
	else
		return (1);
	if (!check_input2(&school))
		thread_create(&school);
	i = 0;
	while (i < school.number_philo)
	{
		pthread_join(school.philosophers[i].philo, NULL);
		i++;
	}
}
