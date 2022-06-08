/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:44:23 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/06 22:58:38 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_global
{
	pthread_mutex_t *mutex;
	int				die;
	int 			eat;
	int				sleep;
	int				meals;
} t_global ;

typedef struct s_philo
{
	int 		id;
	int 		last_meal;
	pthread_t 	philo;
	t_global	rules;
} t_philo ;



long long	ft_atoi(const char *str);

# endif