/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:15:54 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:26:39 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_index(int elem, int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		if (arr[i] == elem)
			return (i);
	return (-1);
}

void	ft_index_stack_a(t_pms *pms)
{
	int		i;
	t_node	*elem;

	elem = pms->begin_a;
	i = -1;
	while (++i < pms->ac)
	{
		elem->index = find_index(elem->value, pms->arr, pms->ac);
		elem = elem->next;
	}
}

int	ft_is_stack_sorted(t_pms *pms, char stack, int is_five)
{
	int		rsort;
	int		pos;
	t_node	*lst;
	int		i;
	int		size;

	lst = NULL;
	ft_choose_size_lst(&lst, stack, &size, pms);
	rsort = 0;
	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (lst->index > lst->next->index
			&& lst->index + is_five != pms->ac - 1 - pos)
			return (NOT_SORTED);
		else if (lst->index + is_five == pms->ac - 1 - pos
			&& !rsort && i != pms->ac - 1)
			rsort = 1;
		lst = lst->next;
	}
	if (rsort)
		return (RSORTED);
	return (SORTED);
}

int	ft_find_stack_position(t_pms pms, int index, char stack)
{
	int		i;
	t_node	*lst;

	if (stack == 'A')
		lst = pms.begin_a;
	if (stack == 'B')
		lst = pms.begin_b;
	i = -1;
	while (++i < pms.ac)
	{
		if (lst->index == index)
			return (i);
		lst = lst->next;
	}
	return (-1);
}
