/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:30 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/19 12:35:44 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// static void	ft_put_down_forks(t_philo *philo)
// {
// 	sem_post(philo->tdata->eating_forks);
// 	usleep(100);
// 	sem_post(philo->tdata->eating_forks);
// 	usleep(100);
// }

// static void	ft_take_forks(t_philo *philo)
// {
// 	sem_wait(philo->tdata->eating_forks);
// 	ft_print(philo, "has taken a right fork");
// 	sem_wait(philo->tdata->eating_forks);
// 	ft_print(philo, "has taken a left fork");
// 	if (philo->tdata->general_condition == SOMEONE_IS_DEAD)
// 		return (ft_put_down_forks(philo));
// }

// static void	ft_philo_eating(t_philo *philo)
// {
// 	ft_take_forks(philo);
// 	sem_wait(philo->ready);
// 	ft_print(philo, "is eating");
// 	ft_improved_usleep(philo->tdata->ms_eat);
// 	// if (philo->count_eating != -1)
// 	// 	philo->count_eating--;
// 	// ft_put_down_forks(philo);
// 	// philo->ms_last_eating = ft_ms_timestamp() - philo->tdata->time_start;
// 	// sem_post(philo->ready);
// }

static void	ft_philo_sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_improved_usleep(philo->tdata->ms_sleep);
}

void	ft_philo_routine(t_philo *philo)
{
	while (1)
	{
		ft_print(philo, "is thinking");
		// ft_philo_eating(philo);
		ft_philo_sleeping(philo);
		// philo->tdata->general_condition = SOMEONE_IS_DEAD;
		if (philo->tdata->general_condition == SOMEONE_IS_DEAD
			|| philo->count_eating == 0)
			break;
	}
	// waitpid(philo->pid, NULL, 0);
	(void )philo;
	exit(0);
}
