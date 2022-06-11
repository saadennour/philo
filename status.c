/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/12 00:22:37 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stats(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->rules->print);
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
	pthread_mutex_unlock(&philo->rules->print);
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
		//usleep(philo->rules->sleep * 1000);
		gettimeofday(&final, NULL);
		time = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
		//printf ("%d\n", time);
		if (time >= (philo->rules->die * 1000))
		{
			philo_stats(philo, 5);
			exit (0);
		}
	}
	return ;
}

void	dinning(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	gettimeofday(&initial, NULL);
	while (time < (philo->rules->eat * 1000))
	{
		gettimeofday(&final, NULL);
		time = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
	}
	//usleep(philo->rules->eat * 1000);
	return ;
}

void	timer()
{
	struct timeval	initial;
	//struct timeval	final;
	//int				time;

	//time = 0;
	gettimeofday(&initial, NULL);
	printf ("%ld seconds and %d microsec\n", initial.tv_sec, initial.tv_usec);
}