/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:03:45 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:03:46 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_pms *pms, int is_five)
{
	int	sorted;

	sorted = ft_is_stack_sorted(pms, 'A', is_five);
	if (sorted == RSORTED && pms->ac == 2)
		sa(pms, 1);
	else if (sorted == RSORTED && pms->begin_a->index - is_five == 2)
		ra(pms, 1);
	else if (sorted == RSORTED && pms->begin_a->index - is_five == 1)
		rra(pms, 1);
	else if (sorted == NOT_SORTED && pms->begin_a->prev->index - is_five == 0)
	{
		sa(pms, 1);
		rra(pms, 1);
	}
	else if (sorted == NOT_SORTED && pms->begin_a->prev->index - is_five == 1)
	{
		sa(pms, 1);
		ra(pms, 1);
	}
	else if (sorted == NOT_SORTED && pms->begin_a->prev->index - is_five == 2)
		sa(pms, 1);
}

static	void	ft_sort_five(t_pms *pms)
{
	int	sorted;
	int	zero;
	int	last;

	sorted = ft_is_stack_sorted(pms, 'A', 0);
	zero = ft_find_stack_position(*pms, 0, 'A');
	last = ft_find_stack_position(*pms, pms->ac - 1, 'A');
	if (sorted == RSORTED)
		ft_to_the_top(0, 'A', pms);
	else
	{
		ft_to_the_top(pms->ac - 1, 'A', pms);
		pb(pms, 1);
		ft_to_the_top(0, 'A', pms);
		pb(pms, 1);
		ft_sort_three(pms, 1);
		pa(pms, 1);
		pa(pms, 1);
		ra(pms, 1);
	}
}

void	ft_sort(t_pms *pms)
{
	if (pms->ac <= 3)
		ft_sort_three(pms, 0);
	else if (pms->ac <= 5)
		ft_sort_five(pms);
	else
		ft_butterfly(pms);
}
