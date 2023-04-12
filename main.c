/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 15:57:14 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philosophers(t_times *times)
{
	int	i;
	
	i = 0;
	times->tid_pointers = (pthread_t *)malloc(sizeof(pthread_t) * times->times[0]);
	while (i < times->times[0])
	{
		pthread_create(&times->tid_pointers[i], NULL, &ft_routine, NULL)
		i++;
	}

	
}



int	main(int ac, char **av)
{
	t_times	times;

	if ((ac == 5 || ac == 6) && !check_input(av))
		store_values(av, &times);
	else
		return (1);
	if (check_input2(&times))
	{	
		create_philosophers(&times);
	}
}
