/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:30:10 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/22 01:35:46 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ft_atoi(av[1]) == 0)
		return (0);
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-')
			return (0);
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (0);
	return (1);
}
