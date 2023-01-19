/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:27 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/16 10:23:15 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_philo *philo, char *message)
{
	if (philo->tdata->general_condition == EVERYBODY_ALIVE)
	{
		pthread_mutex_lock(philo->tdata->output_mutex);
		printf("%ld %d %s\n", philo->tdata->ms_passed,
			philo->philo_index, message);
		pthread_mutex_unlock(philo->tdata->output_mutex);
	}
}

static void	*ft_kill_philo(t_pms *pms, int philo_index)
{
	pms->philos[philo_index].tdata->general_condition = SOMEONE_IS_DEAD;
	pthread_mutex_lock(pms->tdata->output_mutex);
	printf("%ld %d is died\n", pms->tdata->ms_passed, philo_index);
	pthread_mutex_unlock(pms->tdata->output_mutex);
	pthread_mutex_unlock(pms->philos[philo_index].left_fork->mutex);
	pthread_mutex_unlock(pms->philos[philo_index].right_fork->mutex);
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
				< pms->tdata->ms_passed
				&& pms->philos[i].left_fork->philo_index != i
				&& pms->philos[i].right_fork->philo_index != i)
				return (ft_kill_philo(pms, i));
		}
		if (done_eating >= pms->amount)
			return (NULL);
	}
	return (NULL);
}

int	ft_create_threads(t_pms *pms)
{
	int			i;
	pthread_t	*philos_threads;
	pthread_t	checker_thread;

	philos_threads = (pthread_t *)malloc(sizeof(pthread_t) * pms->amount);
	if (!philos_threads)
		return (NOT_OK);
	if (pthread_create(&checker_thread, NULL, ft_check_condition, pms))
		return (NOT_OK);
	i = -1;
	while (++i < pms->amount)
		if (pthread_create(&philos_threads[i], NULL,
				ft_philo_routine, &pms->philos[i]))
			return (NOT_OK);
	i = -1;
	while (++i < pms->amount)
		if (pthread_join(philos_threads[i], NULL))
			return (NOT_OK);
	if (pthread_join(checker_thread, NULL))
		return (NOT_OK);
	free(philos_threads);
	return (OK);
}
