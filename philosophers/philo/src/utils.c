/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:23 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/15 13:52:24 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atoi(const char *str)
{
	long	sum;
	int		sign;
	int		found;

	sum = 0;
	sign = 1;
	found = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	if (sum > MAXINT || sum < MININT)
		return ((long) MAXINT + 1);
	return (sum * sign);
}

long	ft_ms_timestamp(void)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_improved_usleep(long time_ms)
{
	long	start;
	long	current;

	start = ft_ms_timestamp();
	current = ft_ms_timestamp();
	while ((current - start) < time_ms)
	{
		usleep(50);
		current = ft_ms_timestamp();
	}
}

void	ft_free(t_pms *pms)
{
	int	i;

	pthread_mutex_destroy(pms->tdata->output_mutex);
	free(pms->tdata->output_mutex);
	free(pms->philos);
	i = -1;
	while (++i < pms->amount)
		pthread_mutex_destroy(pms->eating_forks[i].mutex);
	free(pms->eating_forks);
	free(pms->eating_forks_mutexes);
}
