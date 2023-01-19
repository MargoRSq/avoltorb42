/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:25:28 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/15 14:14:20 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define MAXINT 2147483647
# define MININT -2147483647

enum e_execution_result
{
	OK = 0,
	NOT_OK = 1
};
enum e_condition
{
	SOMEONE_IS_DEAD = 2,
	EVERYBODY_ALIVE = 4
};

typedef struct s_eating_fork
{
	pthread_mutex_t		*mutex;
	int					mutex_index;
	int					philo_index;
}	t_efork;

typedef struct s_time
{
	int					ms_die;
	int					ms_eat;
	int					ms_sleep;
	long				ms_passed;
	long				time_start;
	pthread_mutex_t		*output_mutex;
	enum e_condition	general_condition;
}	t_time;

typedef struct s_philosopher
{
	int					philo_index;
	int					ms_last_eating;
	int					count_eating;
	t_efork				*right_fork;
	t_efork				*left_fork;
	t_time				*tdata;
	pthread_t			id_thread;
}				t_philo;

typedef struct s_params
{
	int					amount;
	int					count_eating;
	t_efork				*eating_forks;
	t_philo				*philos;
	t_time				*tdata;
	pthread_mutex_t		*eating_forks_mutexes;
}				t_pms;

/*
	init.c
*/
int		ft_init(t_pms *pms);

/*
	utils.c
*/
long	ft_atoi(const char *str);
long	ft_ms_timestamp(void);
void	ft_improved_usleep(long time_ms);
void	ft_free(t_pms *pms);

/*
	parser.c
*/
int		ft_parse(int argc, char **argv, t_pms *pms, t_time *tdata);

/*
	threads.c
*/
int		ft_create_threads(t_pms *pms);
void	ft_print(t_philo *philo, char *message);
void	ft_print_time(t_philo *philo, long start, long end, char *message);
void	*ft_philo_routine(void *vphilo);

#endif