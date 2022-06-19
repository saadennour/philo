/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 21:43:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/19 03:02:37 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_stats(t_philo *philo, int status)
{
	struct timeval	final;
	long int		time;

	pthread_mutex_lock(&philo->rules->print);
	gettimeofday(&final, NULL);
	time = sec_to(philo->rules->time, final);
	if (status == 1)
		printf ("%ld: %d has taken a fork\n", time, philo->id);
	else if (status == 2)
		printf ("%ld: %d is eating\n", time, philo->id);
	else if (status == 3)
		printf ("%ld: %d is sleeping\n", time, philo->id);
	else if (status == 4)
		printf ("%ld: %d is thinking\n", time, philo->id);
	else if (status == 5)
	{
		printf ("%ld: %d died\n", time, philo->id);
		return ;
	}
	pthread_mutex_unlock(&philo->rules->print);
}

void	bedroom(t_philo *philo)
{
	philo_stats(philo, 3);
	ft_usleep(philo->rules->sleep * 1000);
}

void	dining(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);
	philo_stats(philo, 2);
	ft_usleep (philo->rules->eat * 1000);
	philo->meals -= 1;
}

void	tombstone(t_philo *philo, int *num_philo)
{
	int			i;
	static int	j;

	i = j;
	if (philo[i].meals <= 0)
	{
		(*num_philo)--;
		j = i + 1;
	}
}

int	hades(t_philo *philo, int ac, int num_philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < philo->rules->num_philo)
		{
			if (kerberos(philo, i) == 1)
				return (1);
			if (ac == 6)
			{
				tombstone(philo, &num_philo);
				{
					if (num_philo == 0)
					{
						pthread_mutex_lock(&philo->rules->print);
						return (1);
					}
				}
			}
		}
	}
}
