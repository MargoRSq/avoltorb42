/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:52 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:35:35 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_valid_args(t_pms pms)
{
	int	i;

	i = -1;
	while (++i < pms.ac)
		if (!(ft_isnumber(pms.av[i])))
			return (write(1, "Error\n", 6));
	return (0);
}

static int	ft_is_duplicate(int idx, int *arr, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
		if (arr[i] == arr[idx] && i != idx)
			return (1);
	return (0);
}

static int	ft_valid_nums(t_pms pms, int is_checker)
{
	int	i;
	int	sorted;

	i = -1;
	sorted = 1;
	while (++i < pms.ac)
	{
		if (ft_is_duplicate(i, pms.arr, pms.ac))
			return (write(1, "Error\n", 6));
		if (sorted && i < pms.ac - 1 && pms.arr[i] > pms.arr[i + 1])
			sorted = 0;
	}
	if (sorted && !is_checker)
		return (1);
	return (0);
}

int	ft_parse(t_pms *pms, int is_checker)
{
	if (!pms->av)
		return (1);
	if (ft_valid_args(*pms) != OK)
		return (ft_clean_exit(pms));
	if (ft_parse_av(pms) != OK)
		return (ft_clean_exit(pms));
	if (ft_valid_nums(*pms, is_checker) != OK)
		return (ft_clean_exit(pms));
	ft_insertion_sort(pms);
	ft_index_stack_a(pms);
	return (0);
}
