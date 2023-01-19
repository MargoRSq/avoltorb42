/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:52:32 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/15 14:23:53 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_pms	pms;
	t_time	tdata;

	if (ft_parse(argc, argv, &pms, &tdata) == NOT_OK)
		return (printf("Invalid arguments\n"));
	pms.tdata = &tdata;
	if (ft_init(&pms) == NOT_OK)
		return (printf("Init error\n"));
	if (ft_create_threads(&pms) == NOT_OK)
		return (printf("Error with threads\n"));
	ft_free(&pms);
	return (EXIT_SUCCESS);
}
