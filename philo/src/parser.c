/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:35 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/15 13:53:27 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isall_nums(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		j = -1;
		while (arg[++j])
			if (!(arg[j] >= '0' && arg[j] <= '9'))
				return (NOT_OK);
	}
	return (OK);
}

int	ft_parse(int argc, char **argv, t_pms *pms, t_time *tdata)
{
	if (ft_isall_nums(argc, argv) == NOT_OK)
		return (NOT_OK);
	if (argc == 5 || argc == 6)
	{
		pms->amount = ft_atoi(argv[1]);
		tdata->ms_die = ft_atoi(argv[2]);
		tdata->ms_eat = ft_atoi(argv[3]);
		tdata->ms_sleep = ft_atoi(argv[4]);
		pms->count_eating = -1;
		if (argc == 6)
			pms->count_eating = ft_atoi(argv[5]);
	}
	else
		return (NOT_OK);
	if (pms->amount == 0 || pms->count_eating == 0
		|| tdata->ms_die == 0
		|| tdata->ms_eat == 0
		|| tdata->ms_sleep == 0)
		return (NOT_OK);
	return (OK);
}
