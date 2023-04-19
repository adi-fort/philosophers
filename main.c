/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/19 11:23:15 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_school *school, int i)
{	
	school->philosophers[i].philo_id = i + 1;
	school->philosophers[i].next_philo_id = i + 1;
	if (i + 1 == school->number_philo)
		school->philosophers[i].next_philo_id = 0;
	pthread_mutex_init(&school->philosophers[i].fork, NULL);
	school->philosophers[i].back = school;
}

void	*ft_routine(void *philo)
{
	t_philo 	*aristotele;	

	aristotele = (t_philo *)philo;
	while (1) 
	{
		if (aristotele->next_philo_id % 2)
			usleep(30000);
		pthread_mutex_lock(&aristotele->fork);
		printf("%d %d has taken a fork\n", right_time(aristotele->back), aristotele->philo_id);	
		pthread_mutex_lock(&aristotele->back->philosophers[aristotele->next_philo_id].fork);
		printf("%d %d has taken a fork\n", right_time(aristotele->back), aristotele->philo_id);
		printf("%d %d is eating\n", right_time(aristotele->back), aristotele->philo_id);
		usleep(aristotele->back->time_to_eat * 1000);
		pthread_mutex_unlock(&aristotele->fork);
		pthread_mutex_unlock(&aristotele->back->philosophers[aristotele->next_philo_id].fork);
		printf("%d %d is sleeping\n", right_time(aristotele->back), aristotele->philo_id);
		usleep(aristotele->back->time_to_sleep * 1000);
		printf("%d %d is thinking\n", right_time(aristotele->back), aristotele->philo_id);
		if ( aristotele->back->times_eat > 0 && (aristotele->back->timing > aristotele->back->times_eat * aristotele->back->time_to_die))
			exit(1);
		if (aristotele->back->time_to_die < aristotele->back->time_to_sleep + aristotele->back->time_to_eat)
		{
			printf("%d %d died\n", right_time(aristotele->back), aristotele->philo_id);
			exit(1);
		}
	}
	return (0);
}

void	thread_create(t_school *school)
{
	int i;

	school->philosophers = (t_philo *)malloc(sizeof(t_philo) * school->number_philo);	
	i = 0;
	while (i < school->number_philo)
	{
		philo_init(school, i);
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
	school.starting_time = time_ms();
	if (!check_input2(&school))
		thread_create(&school);
	i = - 1;
	if (school.number_philo == 1)
	{
		printf("0 1 has taken a fork\n0 1 died\n");
		exit(1);
	}
	while (++i < school.number_philo)
		pthread_join(school.philosophers[i].philo, NULL);
}
