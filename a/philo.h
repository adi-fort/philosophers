/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:42:55 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/21 12:26:48 by adi-fort         ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_id;
	int				next_philo_id;
	pthread_mutex_t	fork;
	pthread_mutex_t death;
	long int		death_counter;
	struct s_school	*back;
}	t_philo;

typedef struct s_school
{
	t_philo			*philosophers;
	long int		number_philo;
	long int		time_to_sleep;
	long int		time_to_die;
	long int		time_to_eat;
	long int		times_eat;
	long int		sum;
	long int		m;
	int				starting_time;
	int				timing;
}	t_school;

int					check_input(char **av);
void				store_values(int ac, char **av, t_school *school);
int					check_input2(t_school *school);
void				thread_create(t_school *school);
void				*ft_routine(void *school);
int					ft_isdigit(int c);
long int			ft_atoi(const char *str);
int					time_ms(void);
int					right_time(t_school *school);
int					oracle(t_school *school);
#endif
