/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 14:57:00 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int main(int ac, char **av)
{
	t_times times;
	
	if ((ac == 5 || ac == 6) && !check_input(av))
		store_values(av, &times);
	else
		return (1);
	if (check_input2(&times))
		printf("a");
}
