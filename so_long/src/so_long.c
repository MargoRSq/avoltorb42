/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:33 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/07 17:10:05 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_params	pms;

	if (ft_invalid_args(ac))
		return (1);
	if (ft_map_error(av[1], &pms.map) || !ft_setup(av[1], &pms.map))
		return (write(1, "Error\n", 7));
	ft_init_mlx(&pms.objs, pms.map);
	ft_init_game(&pms.game);
	ft_draw_map(&pms);
	mlx_key_hook(pms.objs.win, ft_key_event, &pms);
	mlx_hook(pms.objs.win, 17, 1L << 17, ft_exit_hook, &pms);
	mlx_loop(pms.objs.mlx);
	ft_exit(&pms);
}
