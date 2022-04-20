/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:37 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/19 07:59:17 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_init_semaphors(t_pms *pms)
{
	sem_unlink("forks");
	sem_unlink("stop_eating");
	sem_unlink("output");
	// sem_unlink("stop_death");
	pms->tdata->eating_forks = sem_open("forks", O_CREAT, 0700, pms->amount);
	if (pms->tdata->eating_forks == SEM_FAILED)
		ft_exit("Error with forks semaphors\n");
	pms->tdata->output = sem_open("output", O_CREAT, 0700, 1);
	if (pms->tdata->output == SEM_FAILED)
		ft_exit("Error with output semaphor\n");
	pms->tdata->main_sem = sem_open("main", O_CREAT, 0700, 1);
	if (pms->tdata->main_sem == SEM_FAILED)
		ft_exit("Error with main process semaphor\n");
	pms->tdata->stop_eating = sem_open("stop_eating", O_CREAT, 0700, 1);
	if (pms->tdata->stop_eating == SEM_FAILED)
		ft_exit("Error with semaphors 4\n");
}


static void	ft_init_philos(t_pms *pms)
{
	int		i;
	t_philo	*philos;
	// char	*name;
	char	buffer[250];

	philos = (t_philo *)malloc(sizeof(t_philo) * pms->amount);
	if (!philos)
		ft_exit("Error with philos allocation\n");
	i = -1;
	// sem_open(PHSEM)
	while (++i < pms->amount)
	{
		philos[i].ready = sem_open(make_semaphore_name(PHSEM, buffer, i),
				O_CREAT, 0700, 1);
		sem_post(philos[i].ready);
		philos[i].tdata = pms->tdata;
		philos[i].philo_index = i;
		philos[i].ms_last_eating = 0;
		philos[i].count_eating = pms->count_eating;
	}
	pms->tdata->ms_passed = 0;
	pms->tdata->general_condition = EVERYBODY_ALIVE;
	pms->philos = philos;
}

void	ft_init(t_pms *pms)
{
	ft_init_semaphors(pms);
	ft_init_philos(pms);
}
