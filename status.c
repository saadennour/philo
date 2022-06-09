/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/09 01:19:54 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stats(t_philo *philo, int status)
{
	if (status == 1)
		printf ("%d has taken a fork\n", philo->id);
	else if (status == 2)
		printf ("%d is eating\n", philo->id);
	else if (status == 3)
		printf ("%d is sleeping\n", philo->id);
	else if (status == 4)
		printf ("%d is thinking\n", philo->id);
	else if (status == 5)
		printf ("%d died\n", philo->id);
}

void	office(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	gettimeofday(&initial, NULL);
	while (time != philo->rules->eat)
	{
		philo_stats(philo, 4);
		usleep(10);
		gettimeofday(&final, NULL);
		time = initial.tv_usec - final.tv_usec;
		if (time >= philo->rules->die)
		{
			philo_stats(philo, 5);
			exit (0);
		}
	}
}

void	bedroom(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	gettimeofday(&initial, NULL);
	while (time != philo->rules->sleep)
	{
		philo_stats(philo, 3);
		usleep(10);
		gettimeofday(&final, NULL);
		time = initial.tv_usec - final.tv_usec;
		if (time >= philo->rules->die)
		{
			philo_stats(philo, 5);
			exit (0);
		}
	}
}