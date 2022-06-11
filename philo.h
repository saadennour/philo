/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/12 00:11:33 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_global
{
	pthread_mutex_t *mutex;
	pthread_mutex_t print;
	int				die;
	int 			eat;
	int				sleep;
	int				meals;
	int				num_philo;
} t_global ;

typedef struct s_philo
{
	int 		id;
	int 		last_meal;
	pthread_t 	philo;
	t_global	*rules;
} t_philo ;



long long	ft_atoi(const char *str);
void		philo_stats(t_philo *philo, int status);
void		office(t_philo *philo);
void		bedroom(t_philo *philo);
void		dinning(t_philo *philo);
void		ft_putnbr(int nb);
void		timer();

# endif