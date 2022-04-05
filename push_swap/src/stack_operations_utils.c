/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:09:54 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:51:00 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_choose_size_lst(t_node **lst, char stack, int *size, t_pms *pms)
{
	if (stack == 'A')
	{
		*size = pms->size_a;
		*lst = pms->begin_a;
	}
	else
	{
		*size = pms->size_b;
		*lst = pms->begin_b;
	}
}

void	ft_cast_operation(int times, t_pms *pms, void (*op)(t_pms*, int))
{
	while (times-- > 0)
		op(pms, 1);
}

void	ft_to_the_top(int index, char stack, t_pms *pms)
{
	int	pos;
	int	size;

	if (stack == 'A')
		size = pms->size_a;
	else
		size = pms->size_b;
	pos = ft_find_stack_position(*pms, index, stack);
	if (stack == 'A' && pos > size / 2)
		ft_cast_operation(size - pos, pms, rra);
	else if (stack == 'A')
		ft_cast_operation(pos, pms, ra);
	else if (stack == 'B' && pos > size / 2)
		ft_cast_operation(size - pos, pms, rrb);
	else if (stack == 'B')
		ft_cast_operation(pos, pms, rb);
}

void	ft_free_stack(char stack, t_pms *pms)
{
	t_node	*lst;
	t_node	*tmp;
	int		size;

	ft_choose_size_lst(&lst, stack, &size, pms);
	while (size--)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
	}
}
