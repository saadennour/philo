/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 23:46:04 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/21 01:50:17 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	private_info(t_philo *philo, int ac, char **av, t_global *rules)
{
	int	i;
	int	num_philo;

	i = 0;
	num_philo = ft_atoi(av[1]);
	while (i < num_philo)
	{
		philo[i].id = i + 1;
		philo[i].rules = doc_strange(av, rules);
		philo[i].meals = 0;
		if (ac == 6)
			philo[i].meals = ft_atoi(av[5]);
		i++;
	}
	create_philo(philo, num_philo);
}

static void	part_two(t_philo *philo, int num_philo)
{
	int	i;	

	i = -1;
	while (++i < num_philo)
	{
		if (philo[i].id % 2 == 0)
		{
			gettimeofday(&philo[i].last_meal, NULL);
			pthread_create(&philo[i].philo, NULL, &philo_born, &philo[i]);
		}
	}
}

void	create_philo(t_philo *philo, int num_philo)
{
	int			i;
	static int	j;

	i = -1;
	while (++i < num_philo)
	{
		if (philo[i].id % 2 == 1)
		{
			gettimeofday(&philo[i].last_meal, NULL);
			if (j == 0)
			{
				gettimeofday(&philo->rules->time, NULL);
				j++;
			}
			pthread_create(&philo[i].philo, NULL, &philo_born, &philo[i]);
		}
	}
	usleep(200);
	part_two(philo, num_philo);
}

int	kerberos(t_philo *philo, int i)
{
	struct timeval	final;
	int				clock;

	clock = 0;
	gettimeofday(&final, NULL);
	clock = sec_to(philo[i].last_meal, final);
	if (clock >= philo[i].rules->die)
	{
		philo_stats(philo, 5);
		return (1);
	}
	return (0);
}
