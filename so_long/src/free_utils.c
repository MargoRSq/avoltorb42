/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:47 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:04:48 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_free_gnl(char *line, int code)
{
	free(line);
	return (code);
}

int	ft_exit_hook(t_params *pms)
{
	mlx_loop_end(pms->objs.mlx);
	return (0);
}

int	ft_exit(t_params *pms)
{
	int	i;

	mlx_destroy_image(pms->objs.mlx, pms->objs.car);
	mlx_destroy_image(pms->objs.mlx, pms->objs.toto);
	mlx_destroy_image(pms->objs.mlx, pms->objs.road);
	mlx_destroy_image(pms->objs.mlx, pms->objs.sand);
	mlx_destroy_image(pms->objs.mlx, pms->objs.finish);
	mlx_destroy_image(pms->objs.mlx, pms->objs.trophy);
	mlx_destroy_image(pms->objs.mlx, pms->objs.score);
	mlx_destroy_window(pms->objs.mlx, pms->objs.win);
	mlx_destroy_display(pms->objs.mlx);
	free(pms->objs.mlx);
	i = -1;
	while (++i < pms->map.height)
		free(pms->map.map[i]);
	free(pms->map.map);
	return (0);
}
