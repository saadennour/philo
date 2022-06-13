/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/14 00:50:23 by sfarhan          ###   ########.fr       */
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
		gettimeofday(&final, NULL);
		time = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
		if (time >= (philo->rules->die * 1000))
		{
			philo_stats(philo, 5);
			exit (0);
		}
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
		time = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
		//printf ("%d\n", time);
	}
	philo->last_meal = ((final.tv_sec - initial.tv_sec) * 1000000) + final.tv_usec - initial.tv_usec;
	philo->meals -= 1;
	printf ("%d\n", philo->meals);
	return ;
}


void	tombstone(t_philo *philo)
{
	int	i;
	int	j;
	int	num_philo;
	
	j = -1;
	num_philo = philo->rules->num_philo;
	while (num_philo != 0)
	{
		i = 0;	
		while (i < philo->rules->num_philo)
		{
			if (philo[i].meals == 0 && i > j)
			{
				j = i;
				num_philo--;
			}
			i++;
		}
	}
	//printf ("%d\n", num_philo);
	exit (0);
}

// void	hades(t_philo **philo, int ac)
// {
// 	// struct timeval	time;
// 	// int clock;
// 	int	i;
	
// 	i = 0;
// 	// gettimeofday(&time, NULL);
// 	// clock = time.tv_sec - philo->last_meal;
// 	// if (clock >= philo->rules->die)
// 	// {
// 	// 	philo_stats(philo, 5);
// 	// 	exit (0);
// 	// }
// 	while (i < philo->rules->num_philo)
// 	{
// 		if (ac == 6)
// 			tombstone(philo[i]);
// 	} 
// }