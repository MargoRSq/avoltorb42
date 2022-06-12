/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:32 by avoltorb          #+#    #+#             */
/*   Updated: 2022/06/12 17:12:32 by svyatoslav       ###   ########.fr       */
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

// static void	initprocess(t_data *data)
// {
// 	pid_t	pid;

// 	data->id = 0;
// 	update_time(data);
// 	while (data->id < data->number)
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 		{
// 			printf("ERROR_PROCESS INIT");
// 			exit (0);
// 		}
// 		if (pid == 0)
// 		{
// 			ft_sit(data);
// 			update_time(data);
// 			monitoring(data);
// 			update_time(data);
// 			ft_action(data);
// 		}
// 		data->children_pids[data->id] = pid;
// 		data->id++;
// 	}
// }

static void	wait_philos(t_pms *pms, pid_t checker_pid)
{
	int	*stat_loc;
	int	i;

	i = -1;

	stat_loc = malloc(sizeof(int));
	waitpid(checker_pid, NULL, 0);
	while (pms->pids[++i])
	{
		waitpid(pms->pids[i], stat_loc, 0);
		// printf("stat_loc = %d\n", *stat_loc);
		// if (*stat_loc == 256)
		// {
		// 	exit_all(data);
		// 	break ;
		// }
	}
	free(stat_loc);
}


static void	*ft_kill_philo(t_pms *pms, int philo_index)
{
	sem_wait(pms->philos[philo_index].ready);
	pms->philos[philo_index].tdata->general_condition = SOMEONE_IS_DEAD;
	sem_post(pms->tdata->stop_eating);
	sem_wait(pms->tdata->output);
	printf("%ld %d is died\n", pms->tdata->ms_passed, philo_index);
	sem_post(pms->tdata->output);
	sem_post(pms->tdata->main_sem);
	return (NULL);
}

static void	*ft_check_condition(void *v_pms)
{
	int		i;
	int		done_eating;
	t_pms	*pms;

	pms = (t_pms *)v_pms;
	while (1)
	{
		i = -1;
		done_eating = 0;
		while (++i < pms->amount)
		{
			pms->tdata->ms_passed = ft_ms_timestamp() - pms->tdata->time_start;
			if (pms->philos[i].count_eating == 0)
				done_eating++;
			if (pms->philos[i].ms_last_eating + pms->tdata->ms_die \
				< pms->tdata->ms_passed)
				// && pms->philos[i].left_fork->philo_index != i
				// && pms->philos[i].right_fork->philo_index != i)
				return (ft_kill_philo(pms, i));
		}
		if (done_eating >= pms->amount)
			return (NULL);
	}
	return (NULL);
}


static void	ft_create_processes(t_pms *pms)
{
	int	i;
	pid_t	pid;
	pid_t	checker_pid;

	// int	checker_pid;

	i = -1;
	pms->pids = (pid_t *) malloc(sizeof(pid_t) * pms->amount);
	checker_pid = fork();
	if (checker_pid == 0)
	{
		ft_check_condition(pms);
		exit(0);
	}
	while (++i < pms->amount)
	{
		pid = fork();
		// pms->philos[i].pid = fork();
		if (pid == 0)
		{
			ft_philo_routine(&pms->philos[i]);
			// exit(0);
		}
		pms->philos[i].pid = pid;
		pms->pids[i] = pid;
		usleep(300);
	}
	wait_philos(pms, checker_pid);
}

// static void	wait_philos(t_pms *pms, pid_t checker_pid)
// {
// 	int	*stat_loc;
// 	int	i;

// 	i = -1;

// 	stat_loc = malloc(sizeof(int));
// 	waitpid(checker_pid, NULL, 0);
// 	while (pms->pids[++i])
// 	{
// 		waitpid(pms->pids[i], stat_loc, 0);
// 		// printf("stat_loc = %d\n", *stat_loc);
// 		// if (*stat_loc == 256)
// 		// {
// 		// 	exit_all(data);
// 		// 	break ;
// 		// }
// 	}
// 	free(stat_loc);
// }


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
	// sem_wait(tdata.main_sem);
	ft_free(&pms);
	// int *a = (int *)malloc(sizeof(int));
	// waitpid(-1, a, 0);
	exit(0);
}
