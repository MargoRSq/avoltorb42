/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:04:53 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/04 11:04:54 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_invalid_args(int ac)
{
	if (ac != 2)
		return (write(1, "Incorrect number of arguments!\n", 32));
	return (0);
}

int	ft_check_filename(char *filename)
{
	int			len;
	char		*begin;

	len = ft_strlen(filename);
	begin = (char *) &filename[(len - 4)];
	if (ft_strncmp(begin, ".ber", 4) == 0)
		return (1);
	return (0);
}
