/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:58 by sfarhan           #+#    #+#             */
/*   Updated: 2022/05/24 23:04:52 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_born(int i)
{
	printf ("philo %d is born\n", i);
}

int main(int ac, char **av)
{
	int	thread_id;
	int num_philo;
	int	i;

	i = 1;
	num_philo = ft_atoi(av[1]);
	if (ac < 5)
		printf ("Error\n");
	else
	{
		while (num_philo--)
		{
			pthread_create(&thread_id, NULL, philo_born, i);
			i++;
		}
	}
	return (0);
}