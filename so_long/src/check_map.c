/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:51 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:52:18 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static void	ft_fill_params(char c, t_valid_map *vmap_pms)
{
	if (c == 'C')
		vmap_pms->collectible = 1;
	else if (c == 'P')
		vmap_pms->start = 1;
	else if (c == 'E')
		vmap_pms->exit = 1;
}

static int	ft_isvalid_fill_line(char *line, int len, t_valid_map *vmap_pms)
{
	int	i;

	i = 0;
	if ((line[0] != '1' || line[len - 1] != '1') && (ft_strlen(line) > 0))
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr("01CEPT", line[i]))
			return (0);
		if (line[i] == 'P' && vmap_pms->start == 1)
			return (0);
		ft_fill_params(line[i], vmap_pms);
		i++;
	}
	return (1);
}

static int	ft_isall_components(t_valid_map map_pms)
{
	if (map_pms.exit + map_pms.collectible + map_pms.start == 3)
		return (1);
	return (0);
}

static int	ft_isvalid_map(char *line, int len, int fd, t_map *map_pms)
{
	t_valid_map	vmap_pms;

	if (!ft_isones(line))
		return (0);
	vmap_pms = (t_valid_map){.exit = 0, .start = 0, .collectible = 0};
	map_pms->height = 1;
	while (line)
	{
		if (ft_strlen(line) - 1 != len && (ft_strlen(line) > 0))
			return (0);
		if (!ft_isvalid_fill_line(line, len, &vmap_pms))
			return (0);
		free(line);
		line = NULL;
		line = get_next_line(fd, line);
		if (!line)
			break ;
		(map_pms->height)++;
	}
	free(line);
	line = NULL;
	return (ft_isall_components(vmap_pms));
}

int	ft_map_error(char *filename, t_map *map_pms)
{
	int		fd;
	int		len;
	char	*line;

	if (!ft_check_filename(filename))
		return (1);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd, NULL);
	if (!line)
		return (1);
	len = ft_strlen(line) - 1;
	map_pms->width = len;
	if (!ft_isvalid_map(line, len, fd, map_pms))
		return (1);
	return (0);
}
