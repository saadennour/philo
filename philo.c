/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:58 by sfarhan           #+#    #+#             */
/*   Updated: 2022/05/31 21:03:10 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;

void	*philo_born()
{
	static int i = 1;
	
	pthread_mutex_lock(&mutex);
	printf ("philo %d is born\n", i);
	i++;
	pthread_mutex_unlock(&mutex);
	return (0);
}

int main(int ac, char **av)
{
	pthread_t	*thread_id;
	int num_philo;
	int	i;

	i = 1;
	thread_id = NULL;
	if (ac < 5)
		printf ("Error\n");
	else
	{
		num_philo = ft_atoi(av[1]);
		thread_id = malloc(sizeof(pthread_t) * num_philo);
		pthread_mutex_init(&mutex, NULL);
		while (i <= num_philo)
		{
			pthread_create(&thread_id[i], NULL, &philo_born, NULL);
			i++;
		}
		i = 1;
		while (i <= num_philo)
		{
			pthread_join(thread_id[i], NULL);
			i++;
		}
	}
	pthread_mutex_destroy(&mutex);
	free(thread_id);
	return (0);
}