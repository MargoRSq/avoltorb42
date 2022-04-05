/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:04:36 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:04:37 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_remove_first_av(int argc, char **argv)
{
	char	**strings;
	int		i;

	strings = (char **)malloc(sizeof(char *) * argc);
	strings[argc - 1] = NULL;
	if (!strings)
		return (NULL);
	i = 0;
	while (++i < argc)
		strings[i - 1] = argv[i];
	return (strings);
}

static void	ft_set_args(int argc, char **argv, t_pms *pms)
{
	if (argc == 1)
		return ;
	else if (argc == 2)
	{
		pms->flag_unpacked = 1;
		pms->ac = ft_get_strnumber(argv[1], ' ');
		pms->av = ft_split(argv[1], ' ');
	}
	else
	{
		pms->ac = argc -1;
		pms->av = ft_remove_first_av(argc, argv);
	}
	pms->size_a = pms->ac;
}

void	ft_init(int argc, char **argv, t_pms *pms)
{
	pms->flag_unpacked = 0;
	pms->size_b = 0;
	pms->begin_a = NULL;
	pms->begin_b = NULL;
	pms->arr = NULL;
	ft_set_args(argc, argv, pms);
}
