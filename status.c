/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/10 01:09:34 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stats(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->rules->print);
	if (status == 1)
	{
		printf ("%d has taken a fork\n", philo->id);
		printf ("%d has taken a fork\n", philo->id);
	}
	else if (status == 2)
		printf ("%d is eating\n", philo->id);
	else if (status == 3)
		printf ("%d is sleeping\n", philo->id);
	else if (status == 4)
		printf ("%d is thinking\n", philo->id);
	else if (status == 5)
		printf ("%d died\n", philo->id);
	pthread_mutex_unlock(&philo->rules->print);
}

void	office(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	philo_stats(philo, 4);
	gettimeofday(&initial, NULL);
	while (time < (philo->rules->eat * 1000))
	{
		usleep(10000);
		gettimeofday(&final, NULL);
		time = final.tv_usec - initial.tv_usec;
		if (time >= (philo->rules->die * 1000))
		{
			philo_stats(philo, 5);
			exit (0);
		}
	}
	return ;
}

void	bedroom(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	philo_stats(philo, 3);
	gettimeofday(&initial, NULL);
	while (time < (philo->rules->sleep * 1000))
	{
		usleep(10000);
		gettimeofday(&final, NULL);
		time = final.tv_usec - initial.tv_usec;
		if (time >= (philo->rules->die * 1000))
		{
			philo_stats(philo, 5);
			exit (0);
		}
	}
	return ;
}