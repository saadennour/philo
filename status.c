/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/17 01:29:25 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stats(t_philo *philo, int status)
{
	struct timeval	final;
	int				time;
	
	pthread_mutex_lock(&philo->rules->print);
	gettimeofday(&final, NULL);
	time = sec_to(philo->rules->time, final);	
	if (status == 1)
		printf ("%d: %d has taken a fork\n", time, philo->id);
	else if (status == 2)
		printf ("%d: %d is eating\n", time, philo->id);
	else if (status == 3)
		printf ("%d: %d is sleeping\n", time,philo->id);
	else if (status == 4)
		printf ("%d: %d is thinking\n", time, philo->id);
	else if (status == 5)
	{
		printf ("%d: %d died\n", time, philo->id);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->print);
}

void	bedroom(t_philo *philo)
{
	struct timeval	initial;
	//struct timeval	final;
	int				time;

	time = 0;
	philo_stats(philo, 3);
	gettimeofday(&initial, NULL);
	// while (time < (philo->rules->sleep))
	// {
	// 	gettimeofday(&final, NULL);
	// 	time = big_ben(initial, final);
	// }
	usleep(philo->rules->sleep * 1000);
	return ;
}

void	dining(t_philo *philo)
{
	//struct timeval	initial;
	//struct timeval	final;
	// int				time;

	// time = 0;
	gettimeofday(&philo->last_meal, NULL);
	philo_stats(philo, 2);
	// if (philo->id == 1)
	// 	printf ("%ld\n", ((philo->last_meal.tv_sec * 1000) + (philo->last_meal.tv_usec / 1000)));
	// while (time < (philo->rules->eat * 1000))
	// {
	// 	gettimeofday(&final, NULL);
	// 	time = big_ben(initial, final);
	// }
	usleep (philo->rules->eat * 1000);
	philo->meals -= 1;
	return ;
}

int	tombstone(t_philo *philo)
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
	return (1);
}

int	hades(t_philo *philo)
{
	struct timeval	final;
	long int		clock;
	int				i;

	i = 0;
	clock = 0;
	while (1)
	{
		i = 0;
		while (i < philo->rules->num_philo)
		{
			gettimeofday(&final, NULL);
			clock = sec_to(philo[i].last_meal, final);
			if (clock >= philo[i].rules->die)
			{
				philo_stats(philo, 5);
				printf ("%ld and %ld, %ld\n", clock, ((philo->last_meal.tv_sec * 1000) + (philo->last_meal.tv_usec / 1000)), ((final.tv_sec * 1000) + (final.tv_usec / 1000)));
				return (1);
			}
			i++;
		}
	}
}
