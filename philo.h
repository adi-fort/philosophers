/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:42:55 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/12 15:55:36 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_times
{
	long int	times[5]; //array di interi dove sono storati gli av[i]
	pthread_t	*tid_pointers; //puntatore al Thread Identifier
}	t_times;



// check_input & store values in structure
int			check_input(char **av);
void		store_values(char **av, t_times *times);
int			check_input2(t_times *times);

//philosophers & routines
void	create_philosophers(t_times *times);
void	*ft_routine(void);

//utils
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
#endif
