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


void	*philo_born(void *guests)
{
	static int i = 1;
	//t_philo	*philo;
	(void)guests;
	//philo = (t_philo*)guests;
	//pthread_mutex_lock(&philo->rules->mutex);
	printf ("philo %d is born\n", i);
	i++;
	//pthread_mutex_unlock(&philo->rules->mutex);
	return (0);
}

t_philo doc_strange(int ac, char **av)
{
	t_philo philo;
	
	philo.rules.die = ft_atoi(av[2]);
	philo.rules.eat = ft_atoi(av[3]);
	philo.rules.sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo.rules.meals = ft_atoi(av[5]);
	return (philo);
}

pthread_mutex_t *init_mutex(int num_philo)
{
	pthread_mutex_t *mutex;
	int				i;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * num_philo);
	while (i < num_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

int main(int ac, char **av)
{
	t_philo		*philo;
	t_global	*rules;
	pthread_mutex_t	*mutex;
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
		rules.mutex = init_mutex(num_philo);
		while (i < num_philo)
		{
			philo[i] = doc_strange(ac, av);
			i++;
		}
		i = 0;
		while (i < num_philo)
		{
			printf ("%d\n", philo[i].rules.eat);
			pthread_create(&philo[i].philo, NULL, &philo_born, &philo);
			i++;
		}
		i = 0;
		while (i < num_philo)
		{
			pthread_join(philo[i].philo, NULL);
			i++;
		}
	}
	//pthread_mutex_destroy(&philo->rules.mutex);
	//free(philo);
	return (0);
}