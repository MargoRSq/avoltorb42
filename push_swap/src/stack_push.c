/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:53:16 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:21:07 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b(t_pms *pms)
{
	t_node	*tmp;

	tmp = pms->begin_a->next;
	pms->begin_a->prev->next = pms->begin_a->next;
	pms->begin_a->next->prev = pms->begin_a->prev;
	if (pms->begin_b)
	{
		pms->begin_a->prev = pms->begin_b->prev;
		pms->begin_a->next = pms->begin_b;
		pms->begin_b->prev->next = pms->begin_a;
		pms->begin_b->prev = pms->begin_a;
		pms->begin_b = pms->begin_a;
	}
	else
	{
		pms->begin_b = pms->begin_a;
		pms->begin_a->next = pms->begin_b;
		pms->begin_a->prev = pms->begin_b;
	}
	pms->begin_a = tmp;
}

static void	push_a(t_pms *pms)
{
	t_node	*tmp;

	tmp = pms->begin_b->next;
	pms->begin_b->prev->next = pms->begin_b->next;
	pms->begin_b->next->prev = pms->begin_b->prev;
	if (pms->begin_a)
	{
		pms->begin_b->prev = pms->begin_a->prev;
		pms->begin_b->next = pms->begin_a;
		pms->begin_a->prev->next = pms->begin_b;
		pms->begin_a->prev = pms->begin_b;
		pms->begin_a = pms->begin_b;
	}
	else
	{
		pms->begin_a = pms->begin_b;
		pms->begin_a->next = pms->begin_a;
		pms->begin_a->prev = pms->begin_a;
	}
	pms->begin_b = tmp;
}

void	pb(t_pms *pms, int print)
{
	if (pms->size_a > 0)
	{
		push_b(pms);
		if (pms->size_a == 1)
			pms->begin_a = NULL;
		pms->size_b++;
		pms->size_a--;
		if (print)
			write(1, "pb\n", 3);
	}
}

void	pa(t_pms *pms, int print)
{
	if (pms->size_b == 0)
		return ;
	push_a(pms);
	if (pms->size_b == 1)
		pms->begin_b = NULL;
	pms->size_b--;
	pms->size_a++;
	if (print)
		write(1, "pa\n", 3);
}
