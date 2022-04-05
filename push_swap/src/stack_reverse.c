/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:53:04 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:20:04 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_pms *pms, int flag)
{
	if (pms->size_a > 1)
	{
		pms->begin_a = pms->begin_a->prev;
		if (flag)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_pms *pms, int flag)
{
	if (pms->size_b)
	{
		pms->begin_b = pms->begin_b->prev;
		if (flag)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_pms *pms, int flag)
{
	rra(pms, 0);
	rrb(pms, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
