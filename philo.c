/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:58 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/15 00:34:49 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*philo_born(void *guests)
{
	t_philo	*philo;

	philo = (t_philo*)guests;
	while (1)
	{
		pthread_mutex_lock(&philo->rules->mutex[philo->id - 1]);
		philo_stats(philo, 1);
		pthread_mutex_lock(&philo->rules->mutex[philo->id % philo->rules->num_philo]);
		philo_stats(philo, 1);
		philo_stats(philo, 2);
		dining(philo);
		pthread_mutex_unlock(&philo->rules->mutex[philo->id - 1]);
		pthread_mutex_unlock(&philo->rules->mutex[philo->id % philo->rules->num_philo]);
		bedroom(philo);
		philo_stats(philo, 4);
	}
	//pthread_mutex_destroy(&philo->rules->mutex);
	return (0);
}

void init_mutex(int num_philo, t_global *rules)
{
	int	i;

	i = 0;
	rules->mutex = malloc(sizeof(pthread_mutex_t) * num_philo);
	pthread_mutex_init(&rules->print, NULL);
	while (i < num_philo)
	{
		pthread_mutex_init(&rules->mutex[i], NULL);
		i++;
	}
}

t_global *doc_strange(char **av, t_global *rules)
{
	rules->num_philo = ft_atoi(av[1]);	
	rules->die = ft_atoi(av[2]);
	rules->eat = ft_atoi(av[3]);
	rules->sleep = ft_atoi(av[4]);
	return (rules);
}

int main(int ac, char **av)
{
	t_philo		*philo;
	t_global	*rules;
	struct timeval time;
	int 		num_philo;
	int			i;

	i = 0;
	if (ac < 5)
		printf ("Error\n");
	else
	{
		num_philo = ft_atoi(av[1]);
		philo = malloc(sizeof(t_philo) * num_philo);
		rules = malloc(sizeof(t_global));
		init_mutex(num_philo, rules);
		i = 0;
		while (i < num_philo)
		{
			philo[i].id = i + 1;
			philo[i].rules = doc_strange(av, rules);
			philo[i].meals = 0;
			if (ac == 6)
				philo[i].meals = ft_atoi(av[5]);
			i++;
		}
		i = 0;
		while (i < num_philo)
		{
			if (philo[i].id % 2 == 1)
			{
				gettimeofday(&time, NULL);
				philo[i].last_meal = (time.tv_sec * 1000000) + time.tv_usec;
				pthread_create(&philo[i].philo, NULL, &philo_born, &philo[i]);
			}
			i++;
		}
		usleep(200);
		i = 0;
		while (i < num_philo)
		{
			if (philo[i].id % 2 == 0)
			{
				gettimeofday(&time, NULL);
				philo[i].last_meal = (time.tv_sec * 1000000) + time.tv_usec;
				pthread_create(&philo[i].philo, NULL, &philo_born, &philo[i]);
			}
			i++;
		}
		while (1)
		{
			if (ac == 6)
				tombstone(philo);
			hades(philo);
		}
		//i = 0;
		// while (i < num_philo)
		// {
		// 	pthread_join(philo[i].philo, NULL);
		// 	i++;
		// }	
	}
	//free(philo);
	return (0);
}