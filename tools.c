/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:56:35 by sfarhan           #+#    #+#             */
/*   Updated: 2022/06/10 22:55:59 by sfarhan          ###   ########.fr       */
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


// void	ft_putnbr(int nb)
// {
// 	unsigned int a;

// 	if (nb < 0)
// 	{
// 		write (1, "-", 1);
// 		nb *= -1;
// 	}
// 	a = nb;
// 	if (a > 9)
// 	{
// 		ft_putnbr(a / 10);
// 		ft_putnbr(a % 10);
// 	}
// 	else
// 	{
// 		a -= '0';
// 		write (1, &a, 1);
// 	}
// }