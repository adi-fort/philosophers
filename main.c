/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/13 11:30:37 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *school)
{
	t_school *a;
	a = (t_school *)school;
	printf("%ld\n", a->number_philo);
	return (a);
}

void	thread_create(t_school *school)
{
	int i;

	i = 0;
	school->philosophers = (t_philo *)malloc(sizeof(t_philo) * school->number_philo);
	while (i < school->number_philo)
	{
		pthread_create(&school->philosophers[i].philo, NULL, &ft_routine, (void *)school);
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
