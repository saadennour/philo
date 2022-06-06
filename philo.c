/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:58 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/06 23:33:25 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;

void	*philo_born(void *guests)
{
	static int i = 1;
	
	pthread_mutex_lock(&mutex);
	printf ("philo %d is born\n", i);
	i++;
	pthread_mutex_unlock(&mutex);
	return (0);
}

t_philo doc_strange(int ac, char **av)
{
	t_philo rules;
	
	rules.die = ft_atoi(av[2]);
	rules.eat = ft_atoi(av[3]);
	rules.sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules.meals = ft_atoi(av[5]);
	return (rules);
}

int main(int ac, char **av)
{
	pthread_t	*thread_id;
	t_philo		*rules = NULL;
	int 		num_philo;
	int			i;

	i = 0;
	thread_id = NULL;
	if (ac < 5)
		printf ("Error\n");
	else
	{
		num_philo = ft_atoi(av[1]);
		rules = malloc(sizeof(t_philo) * num_philo);
		while (i++ < num_philo - 1)
			rules[i] = doc_strange(ac, av);
		thread_id = malloc(sizeof(pthread_t) * num_philo);
		pthread_mutex_init(&mutex, NULL);
		i = 0;
		while (i++ < num_philo)
		{
			printf ("%d\n", i);
			pthread_create(&thread_id[i], NULL, &philo_born, &rules);
		}
		i = 0;
		while (i++ < num_philo)
			pthread_join(thread_id[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	free(thread_id);
	return (0);
}