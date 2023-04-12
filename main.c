/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 08:57:17 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 12:36:10 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int main(int ac, char **av)
{
	t_times times;
	
	if ((ac == 4 || ac == 5) && check_input(av))
		store_values(av, &times);
	else
		return (1);
	if (check_input2(&times))
	{	
		printf("a");
	}
}
