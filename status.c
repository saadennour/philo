/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/15 00:39:57 by sfarhan          ###   ########.fr       */
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
	{
		printf ("%d died\n", philo->id);
		exit (0);
	}
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
		gettimeofday(&final, NULL);
		time = big_ben(initial, final);
		if (time >= (philo->rules->die * 1000))
			philo_stats(philo, 5);
	}
	return ;
}

void	dining(t_philo *philo)
{
	struct timeval	initial;
	struct timeval	final;
	int				time;
	
	time = 0;
	gettimeofday(&initial, NULL);
	while (time < (philo->rules->eat * 1000))
	{
		gettimeofday(&final, NULL);
		time = big_ben(initial, final);
		philo->last_meal = (final.tv_sec * 1000000) + final.tv_usec;
	}
	philo->last_meal = (final.tv_sec * 1000000) + final.tv_usec;
	philo->meals -= 1;
	return ;
}


void	tombstone(t_philo *philo)
{
	int	i;
	int	j;
	int	num_philo;
	
	j = 0;
	num_philo = philo->rules->num_philo;
	while (num_philo != 0)
	{
		i = j;	
		if (philo[i].meals == 0)
		{
			num_philo--;
			j = i + 1;
		}
		i++;
	}
	exit (0);
}

void	hades(t_philo *philo)
{
	struct timeval	final;
	long int clock;
	int	i;
	
	i = 0;
	clock = 0;
	while (1)
	{
		i = 0;
		while (i < philo->rules->num_philo)
		{
			gettimeofday(&final, NULL);
			clock = (final.tv_sec * 1000000) + final.tv_usec;
			clock -= philo[i].last_meal;
			if (clock >= philo[i].rules->die * 1000)
				philo_stats(&philo[i], 5);
			i++;
		}
	}
}

int	big_ben(struct timeval initial, struct timeval final)
{
	int clock;

	clock = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
	return (clock);
}