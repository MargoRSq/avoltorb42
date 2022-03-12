/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:03:56 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:03:57 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define CAR "./image/car.xpm"
# define ROAD "./image/road.xpm"
# define SAND "./image/sand.xpm"
# define SCORE "./image/score.xpm"
# define FINISH "./image/finish.xpm"
# define TOTO "./image/toto.xpm"
# define TROPHY "./image/trophy.xpm"

# define SCORETABLE 'I'
# define SSIDE 64

typedef struct t_map
{
	int		height;
	int		width;
	char	**map;
}	t_map;

typedef struct t_objs
{
	void	*mlx;
	void	*win;
	void	*car;
	void	*road;
	void	*sand;
	void	*toto;
	void	*finish;
	void	*trophy;
	void	*score;
}	t_objs;

typedef struct t_game
{
	int	player_x;
	int	player_y;
	int	steps;
	int	score;
	int	max_score;
}	t_game;

typedef struct t_valid_map
{
	int	collectible;
	int	start;
	int	exit;

}	t_valid_map;

typedef struct t_params
{
	t_map	map;
	t_game	game;
	t_objs	objs;
}	t_params;

int				ft_invalid_args(int ac);
int				ft_key_event(int keycode, t_params *pms);
int				ft_map_error(char *filename, t_map *map_pms);
int				ft_setup(char *filename, t_map *map_pms);
void			ft_init_mlx(t_objs *objs, t_map map_pms);
void			ft_init_game(t_game *game);
void			ft_draw_map(t_params *pms);

int				ft_free_gnl(char *line, int code);
char			*ft_itoa(int nb);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_check_filename(char *filename);
int				ft_isones(char *line);
int				ft_exit_hook(t_params *pms);
int				ft_exit(t_params *pms);
void			ft_put_image(int i, int j, char c, t_params *pms);
void			ft_update_scoretable(t_params *pms);

#endif