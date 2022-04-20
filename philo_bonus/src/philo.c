/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:32 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/19 12:38:54 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static void	destroy_all(t_pms *pms)
// {
// 	// sem_close(data->stop_death);
// 	// sem_unlink("stop_death");
// 	free(pms->philos);
// }

void	ft_free(t_pms *pms)
{
	int	i;

	usleep(pms->tdata->ms_die * 1000);
	sem_close(pms->tdata->eating_forks);
	sem_close(pms->tdata->output);
	sem_close(pms->tdata->main_sem);
	// pthread_mutex_destroy(pms->tdata->output_mutex);
	// free(pms->tdata->output_mutex);
	free(pms->philos);
	sem_unlink("forks");
	sem_unlink("output");
	sem_unlink("main");
	i = -1;
	while (++i < pms->amount)
		sem_close(pms->philos[i].ready);
	// 	pthread_mutex_destroy(pms->eating_forks[i].mutex);
	// free(pms->eating_forks);
	// free(pms->eating_forks_mutexes);
	exit(0);
}

static void	ft_create_processes(t_pms *pms)
{
	int	i;
	// int	checker_pid;

	i = -1;
	while (++i < pms->amount)
	{
		pms->philos[i].pid = fork();
		if (pms->philos[i].pid == 0)
		{
			printf("%d\n", getpid());
			// usleep(50000000);
			ft_philo_routine(&pms->philos[i]);
			exit(0);
			// exit(0);
		}
		usleep(100);
	}
	// checker_pid = fork();
	// if (checker_pid == 0)
}

int	main(int argc, char **argv)
{
	t_pms	pms;
	t_time	tdata;

	ft_parse(argc, argv, &pms, &tdata);
	pms.tdata = &tdata;
	ft_init(&pms);
	tdata.time_start = ft_ms_timestamp();
	// sem_wait(tdata.main_sem);
	ft_create_processes(&pms);
	// ft_create_threads(&pms);
	sem_wait(tdata.main_sem);
	ft_free(&pms);
	exit(0);
}
