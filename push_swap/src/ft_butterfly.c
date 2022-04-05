/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:01 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:06:02 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	ft_choose_fwd(int ac)
{
	if (ac <= 15)
		return (2);
	else if (ac <= 100)
		return (15);
	else if (ac <= 250)
		return (20);
	else if (ac <= 500)
		return (30);
	return (ac / 12);
}

static	void	ft_create_butterfly(t_pms *pms, int fwd)
{
	int	point;

	point = 0;
	while (pms->begin_a)
	{
		if (pms->begin_a->index <= point)
		{
			pb(pms, 1);
			rb(pms, 1);
		}
		else if (pms->begin_a->index <= point + fwd)
			pb(pms, 1);
		else
		{
			ra(pms, 1);
			continue ;
		}
		point++;
	}
}

void	ft_butterfly(t_pms *pms)
{
	int	fwd;

	fwd = ft_choose_fwd(pms->ac);
	ft_create_butterfly(pms, fwd);
	while (pms->size_b > 0)
	{
		ft_to_the_top(pms->size_b - 1, 'B', pms);
		pa(pms, 1);
	}
}
