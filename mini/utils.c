/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:27:44 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/10 11:29:39 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static long long	str_to_nbr(const char *s)
{
	int			i;
	long long	number;

	i = 0;
	number = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			break ;
		number = number * 10 + (s[i] - '0');
		i++;
	}
	return (number);
}

long long	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || \
		str[i] == '\r' || str[i] == '\n' || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (str_to_nbr(&str[i + 1]) * -1);
		else if (str[i] == '+')
			return (str_to_nbr(&str[i + 1]));
		else
			return (str_to_nbr(&str[i]));
	}
	return (0);
}

static void	ft_putcnum(int n)
{
	char	c;

	if (n < 10)
		c = n % 10 + '0';
	else if (n >= 10)
	{
		ft_putcnum(n / 10);
		c = n % 10 + '0';
	}
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putcnum(n * (-1));
	}
	else
		ft_putcnum(n);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
