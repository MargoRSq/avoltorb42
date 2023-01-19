/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:37 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/19 06:18:53 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_init_eforks(t_pms *pms)
{
	int				i;
	t_efork			*eforks;
	pthread_mutex_t	*eforks_mutexes;

	eforks = (t_efork *)malloc(sizeof(t_efork) * pms->amount);
	eforks_mutexes = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * pms->amount);
	if (!eforks || !eforks_mutexes)
		return (NOT_OK);
	i = -1;
	while (++i < pms->amount)
	{
		eforks[i].mutex_index = i;
		pthread_mutex_init(&eforks_mutexes[i], NULL);
		eforks[i].mutex = &eforks_mutexes[i];
	}
	pms->eating_forks = eforks;
	pms->eating_forks_mutexes = eforks_mutexes;
	return (OK);
}

static	int	ft_init_mutexes(t_pms *pms)
{
	pthread_mutex_t	*output_mutex;

	output_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!output_mutex)
		return (NOT_OK);
	pthread_mutex_init(output_mutex, NULL);
	pms->tdata->output_mutex = output_mutex;
	if (ft_init_eforks(pms) == NOT_OK)
		return (NOT_OK);
	return (OK);
}

static int	ft_init_philos(t_pms *pms)
{
	int		i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * pms->amount);
	if (!philos)
		return (NOT_OK);
	i = -1;
	while (++i < pms->amount)
	{
		philos[i].tdata = pms->tdata;
		philos[i].philo_index = i;
		philos[i].right_fork = pms->eating_forks + i;
		philos[i].left_fork = pms->eating_forks + (i + 1) % pms->amount;
		philos[i].ms_last_eating = 0;
		philos[i].count_eating = pms->count_eating;
	}
	pms->tdata->time_start = ft_ms_timestamp();
	pms->tdata->ms_passed = 0;
	pms->tdata->general_condition = EVERYBODY_ALIVE;
	pms->philos = philos;
	return (OK);
}

int	ft_init(t_pms *pms)
{
	if (ft_init_mutexes(pms) == NOT_OK || ft_init_philos(pms) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
