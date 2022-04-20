/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:30 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/15 14:13:35 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork->mutex);
	pthread_mutex_unlock(philo->left_fork->mutex);
	philo->right_fork->philo_index = -1;
	philo->left_fork->philo_index = -1;
}

static void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork->mutex);
	ft_print(philo, "has taken a right fork");
	philo->right_fork->philo_index = philo->philo_index;
	pthread_mutex_lock(philo->left_fork->mutex);
	ft_print(philo, "has taken a left fork");
	philo->left_fork->philo_index = philo->philo_index;
	if (philo->tdata->general_condition == SOMEONE_IS_DEAD)
		return (ft_put_down_forks(philo));
}

static void	ft_philo_eating(t_philo *philo)
{
	ft_take_forks(philo);
	if (philo->left_fork->philo_index == philo->philo_index
		&& philo->right_fork->philo_index == philo->philo_index)
	{
		ft_print(philo, "is eating");
		ft_improved_usleep(philo->tdata->ms_eat);
		if (philo->count_eating != -1)
			philo->count_eating--;
		ft_put_down_forks(philo);
		philo->ms_last_eating = ft_ms_timestamp() - philo->tdata->time_start;
	}
	else
		ft_put_down_forks(philo);
}

static void	ft_philo_sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_improved_usleep(philo->tdata->ms_sleep);
}

void	*ft_philo_routine(void *vphilo)
{
	t_philo	*philo;

	philo = (t_philo *)vphilo;
	while (1)
	{
		ft_print(philo, "is thinking");
		ft_philo_eating(philo);
		ft_philo_sleeping(philo);
		if (philo->tdata->general_condition == SOMEONE_IS_DEAD
			|| philo->count_eating == 0)
			break ;
	}
	return (NULL);
}
