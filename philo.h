/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/15 00:34:25 by sfarhan          ###   ########.fr       */
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
	int				num_philo;
} t_global ;

typedef struct s_philo
{
	int 		id;
	long int 		last_meal;
	int			meals;
	pthread_t 	philo;
	t_global	*rules;
} t_philo ;



long long	ft_atoi(const char *str);
void		philo_stats(t_philo *philo, int status);
void		office(t_philo *philo);
void		bedroom(t_philo *philo);
void		dining(t_philo *philo);
void		ft_putnbr(int nb);
void		tombstone(t_philo *philo);
void		hades(t_philo *philo);
int			big_ben(struct timeval initial, struct timeval final);

# endif