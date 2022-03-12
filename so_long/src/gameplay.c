/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:44 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:04:45 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_scoretable(t_params *pms)
{
	char	*steps;

	ft_put_image(0, 0, SCORETABLE, pms);
	steps = ft_itoa(pms->game.steps);
	mlx_string_put(pms->objs.mlx, pms->objs.win,
		28, 28, 100, steps);
	free(steps);
	steps = NULL;
}

static void	ft_move(t_params *pms, int y, int x)
{
	ft_put_image(pms->game.player_x, pms->game.player_y,
		'0', pms);
	ft_put_image(pms->game.player_x + x, pms->game.player_y + y,
		'P', pms);
	pms->map.map[pms->game.player_y][pms->game.player_x] = '0';
	pms->game.player_y += y;
	pms->game.player_x += x;
	pms->game.steps++;
	ft_update_scoretable(pms);
}

static void	ft_go_action(t_params *pms, int y, int x)
{
	char	c;

	c = pms->map.map[pms->game.player_y + y][pms->game.player_x + x];
	if (c == '0')
		ft_move(pms, y, x);
	else if (c == 'C')
	{
		ft_move(pms, y, x);
		pms->game.score++;
	}
	else if (c == 'E')
	{
		if (pms->game.max_score - pms->game.score == 0)
		{
			printf("You won!\n");
			mlx_loop_end(pms->objs.mlx);
		}
	}
	else if (c == 'T')
	{
		mlx_loop_end(pms->objs.mlx);
		printf("You lost! Toto filed a protest against you!\n%d/%d trophies",
			pms->game.score, pms->game.max_score);
	}
}

int	ft_key_event(int keycode, t_params *pms)
{
	if (keycode == KEY_W)
		ft_go_action(pms, -1, 0);
	else if (keycode == KEY_A)
		ft_go_action(pms, 0, -1);
	else if (keycode == KEY_D)
		ft_go_action(pms, 0, 1);
	else if (keycode == KEY_S)
		ft_go_action(pms, 1, 0);
	else if (keycode == KEY_ESC)
		mlx_loop_end(pms->objs.mlx);
	return (0);
}
