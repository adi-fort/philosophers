/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/05/10 17:52:27 by adi-fort         ###   ########.fr       */
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
	t_philo	*a;	

	a = (t_philo *)philo;
	a->death_counter = 0;
	while (1)
	{
		if (a->next_philo_id % 2 == 0)
			usleep(500);
		if (full(a->back) || a->death_counter == 1)
			break ;
		pthread_mutex_lock(&a->fork);
		printf("%d %d has taken a fork\n", right_time(a->back), a->philo_id);
		pthread_mutex_lock(&a->back->philosophers[a->next_philo_id].fork);
		printf("%d %d has taken a fork\n", right_time(a->back), a->philo_id);
		if (full(a->back) || a->death_counter == 1)
			break ;
		a->starving_time = right_time(a->back);
		printf("%d %d is eating\n", right_time(a->back), a->philo_id);
		usleep(a->back->time_to_eat * 1000);
		pthread_mutex_unlock(&a->fork);
		pthread_mutex_unlock(&a->back->philosophers[a->next_philo_id].fork);	
		if (full(a->back) || a->death_counter == 1)
			break ;
		printf("%d %d is sleeping\n", right_time(a->back), a->philo_id);
		usleep(a->back->time_to_sleep * 1000);
		if (full(a->back) || a->death_counter == 1)
			break ;
		printf("%d %d is thinking\n", right_time(a->back), a->philo_id);
	}
	return (0);
}

void	thread_create(t_school *school)
{
	int	i;

	school->philosophers = (t_philo *)
		malloc(sizeof(t_philo) * school->number_philo);
	i = 0;
	while (i < school->number_philo)
	{
		philo_init(school, i);
		pthread_create(&school->philosophers[i].philo,
			NULL, &ft_routine, (void *)&school->philosophers[i]);
		pthread_detach(school->philosophers[i].philo);
		i++;
	}
}

void	*ft_death(void *school)
{
	int i;
	t_school *b;

	b = (t_school *)school;
	while (1) 
	{
		i = 0;
		while (i < b->number_philo)
		{
			if (b->time_to_die < right_time(b) - b->philosophers[i].starving_time)
			{
				b->philosophers[i].death_counter += 1;
				printf("%d %d is dead\n", right_time(b), i + 1);
				return (0);
			}
			i++;		
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_school	school;
	int			i;

//	school.death_counter = 0;
	if ((ac == 5 || ac == 6) && !check_input(av))
		store_values(ac, av, &school);
	else
		return (1);
	school.starting_time = time_ms();
	if (!check_input2(&school))
		thread_create(&school);
	pthread_create(&school.death, NULL, &ft_death, (void *)&school);
	i = -1;
	if (school.number_philo == 1)
	{
		printf("0 1 has taken a fork\n0 1 died\n");
		return (1);
	}
//	while (++i < school.number_philo)
//		pthread_join(school.philosophers[i].philo, NULL);
	pthread_join(school.death, NULL);
//	while (++i < school.number_philo)
	//pthread_mutex_destroy(&school.philosophers[i].fork);
//	free(school.philosophers);
}
