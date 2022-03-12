/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:49 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:04:50 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ft_put_image(int j, int i, char c, t_params *pms)
{
	if (c == '1')
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.sand, j * SSIDE, i * SSIDE);
	else if (c == '0')
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.road, j * SSIDE, i * SSIDE);
	else if (c == 'T')
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.toto, j * SSIDE, i * SSIDE);
	else if (c == 'P')
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.car, j * SSIDE, i * SSIDE);
	else if (c == 'E')
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.finish, j * SSIDE, i * SSIDE);
	else if (c == 'C')
	{
		pms->game.max_score++;
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.trophy, j * SSIDE, i * SSIDE);
	}
	else if (c == SCORETABLE)
		mlx_put_image_to_window(pms->objs.mlx, pms->objs.win,
			pms->objs.score, j * SSIDE, i * SSIDE);
}

void	ft_init_mlx(t_objs *objs, t_map map_pms)
{
	int	width;
	int	height;

	objs->mlx = mlx_init();
	objs->win = mlx_new_window(objs->mlx,
			SSIDE * map_pms.width, SSIDE * map_pms.height,
			"F1 2021 avoltorb");
	objs->car = mlx_xpm_file_to_image(objs->mlx, CAR, &width, &height);
	objs->toto = mlx_xpm_file_to_image(objs->mlx, TOTO, &width, &height);
	objs->road = mlx_xpm_file_to_image(objs->mlx, ROAD, &width, &height);
	objs->sand = mlx_xpm_file_to_image(objs->mlx, SAND, &width, &height);
	objs->finish = mlx_xpm_file_to_image(objs->mlx, FINISH, &width, &height);
	objs->trophy = mlx_xpm_file_to_image(objs->mlx, TROPHY, &width, &height);
	objs->score = mlx_xpm_file_to_image(objs->mlx, SCORE, &width, &height);
}

void	ft_init_game(t_game *game)
{
	game->steps = 0;
	game->score = 0;
	game->max_score = 0;
	game->player_x = 0;
	game->player_y = 0;
}

int	ft_setup(char *filename, t_map *map_pms)
{
	int	i;
	int	fd;

	fd = open(filename, O_RDONLY);
	map_pms->map = (char **)malloc(sizeof(char *) * map_pms->height);
	if (!map_pms->map)
		return (0);
	i = 0;
	while (i < map_pms->height)
	{
		map_pms->map[i] = get_next_line(fd, NULL);
		i++;
	}
	if (!ft_isones(map_pms->map[0])
		|| !ft_isones(map_pms->map[map_pms->height - 1]))
		return (0);
	return (1);
}

void	ft_draw_map(t_params *pms)
{
	int	i;
	int	j;

	i = 0;
	while (i < pms->map.height)
	{
		j = 0;
		while (j < pms->map.width)
		{
			ft_put_image(j, i, pms->map.map[i][j], pms);
			if (!(pms->game.player_x) && pms->map.map[i][j] == 'P')
			{
				pms->game.player_x = j;
				pms->game.player_y = i;
			}
			j++;
		}
		i++;
	}
	ft_put_image(0, 0, SCORETABLE, pms);
	ft_update_scoretable(pms);
}
