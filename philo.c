/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:58 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/22 01:34:54 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_born(void *guests)
{
	t_philo		*philo;

	philo = (t_philo *)guests;
	while (1)
	{
		pthread_mutex_lock(&philo->rules->mutex[philo->id - 1]);
		philo_stats(philo, 1);
		pthread_mutex_lock(&philo->rules->mutex
		[philo->id % philo->rules->num_philo]);
		philo_stats(philo, 1);
		dining(philo);
		pthread_mutex_unlock(&philo->rules->mutex[philo->id - 1]);
		pthread_mutex_unlock(&philo->rules->mutex
		[philo->id % philo->rules->num_philo]);
		bedroom(philo);
		philo_stats(philo, 4);
	}
	return (0);
}

void	init_mutex(int num_philo, t_global *rules)
{
	int	i;

	i = 0;
	rules->mutex = malloc(sizeof(pthread_mutex_t) * num_philo);
	pthread_mutex_init(&rules->print, NULL);
	pthread_mutex_init(&rules->lunch, NULL);
	while (i < num_philo)
	{
		pthread_mutex_init(&rules->mutex[i], NULL);
		i++;
	}
}

t_global	*doc_strange(char **av, t_global *rules)
{
	rules->num_philo = ft_atoi(av[1]);
	rules->die = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi(av[4]);
	return (rules);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_global	*rules;
	int			num_philo;

	if (ac < 5 || ac > 6)
		printf ("Error\n");
	else
	{
		if (check(ac, av) == 0)
		{
			printf ("Error\n");
			return (0);
		}
		num_philo = ft_atoi(av[1]);
		philo = malloc(sizeof(t_philo) * num_philo);
		rules = malloc(sizeof(t_global));
		init_mutex(num_philo, rules);
		private_info(philo, ac, av, rules);
		while (1)
		{
			if (hades(philo, ac, num_philo) == 1)
				return (1);
		}
	}
	return (0);
}
