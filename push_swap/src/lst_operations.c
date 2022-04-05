/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:04:27 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:16:38 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_lstnew(int value, int index)
{
	t_node	*elem;

	elem = (t_node *)malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->index = index;
	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_lstadd_back(t_node **stack_a, t_node *new)
{
	t_node	*begin;

	if (new == NULL)
		return ;
	begin = *stack_a;
	if (begin)
	{
		if (begin->prev)
		{
			begin->prev->next = new;
			new->prev = begin->prev;
			new->next = begin;
			begin->prev = new;
		}
		else
		{
			begin->prev = new;
			begin->next = new;
			new->prev = begin;
			new->next = begin;
		}
	}
	else
		*stack_a = new;
	return ;
}
