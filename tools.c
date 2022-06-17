/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:56:35 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/17 00:44:34 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	whitespace(char c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			negativity;
	long long	result;

	i = 0;
	negativity = 1;
	result = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		negativity = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * negativity);
}

int	big_ben(struct timeval initial, struct timeval final)
{
	int	clock;

	clock = ((final.tv_sec - initial.tv_sec) * 1000000)
		+ (final.tv_usec - initial.tv_usec);
	return (clock);
}

int	sec_to(struct timeval initial, struct timeval final)
{
	int	clock;

	clock = ((final.tv_sec * 1000) - (initial.tv_sec * 1000))
		+ ((final.tv_usec / 1000) - (initial.tv_usec / 1000));
	return (clock);
}