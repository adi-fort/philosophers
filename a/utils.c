/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-fort <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:39:51 by adi-fort          #+#    #+#             */
/*   Updated: 2023/04/18 09:43:21 by adi-fort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	long int	i;
	long int	num;
	long int	negative;

	negative = 0;
	num = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v')
		|| (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + ((int)str[i] - '0');
		i++;
	}
	if (negative == 1)
		return (num * -1);
	else
		return (num);
}
