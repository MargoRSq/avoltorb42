/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:45 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:40:47 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_pms *pms, int flag)
{
	int	tmp;

	if (pms->size_a > 1)
	{
		tmp = pms->begin_a->value;
		pms->begin_a->value = pms->begin_a->next->value;
		pms->begin_a->next->value = tmp;
		tmp = pms->begin_a->index;
		pms->begin_a->index = pms->begin_a->next->index;
		pms->begin_a->next->index = tmp;
		if (flag)
			write(1, "sa\n", 3);
	}
}

void	sb(t_pms *pms, int flag)
{
	int	tmp;

	if (pms->size_b > 1)
	{
		tmp = pms->begin_b->value;
		pms->begin_b->value = pms->begin_b->next->value;
		pms->begin_b->next->value = tmp;
		tmp = pms->begin_b->index;
		pms->begin_b->index = pms->begin_b->next->index;
		pms->begin_b->next->index = tmp;
		if (flag)
			write(1, "sb\n", 3);
	}
}

void	ss(t_pms *pms, int flag)
{
	sa(pms, 0);
	sb(pms, 0);
	if (flag)
		write(1, "ss\n", 3);
}
