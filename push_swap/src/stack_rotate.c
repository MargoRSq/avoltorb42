/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:55 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:19:01 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_pms *pms, int print)
{
	if (pms->size_a > 1)
	{
		pms->begin_a = pms->begin_a->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_pms *pms, int print)
{
	if (pms->size_b > 1)
	{
		pms->begin_b = pms->begin_b->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_pms *pms, int print)
{
	ra(pms, 0);
	rb(pms, 0);
	if (print)
		write(1, "rr\n", 3);
}
