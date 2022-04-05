/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:07:01 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 15:07:12 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

static void	ft_cmp(t_pms *pms, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(pms, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(pms, 0);
	else if (!ft_strcmp(line, "sa\n"))
		sa(pms, 0);
	else if (!ft_strcmp(line, "sb\n"))
		sb(pms, 0);
	else if (!ft_strcmp(line, "ss\n"))
		ss(pms, 0);
	else if (!ft_strcmp(line, "ra\n"))
		ra(pms, 0);
	else if (!ft_strcmp(line, "rb\n"))
		rb(pms, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(pms, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(pms, 0);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(pms, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(pms, 0);
	else
		write(1, "Error\n", 6);
}

static void	ft_checker(t_pms *pms)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_cmp(pms, line);
		free(line);
	}
	if (ft_is_stack_sorted(pms, 'A', 0) == SORTED)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_pms	pms;

	ft_init(argc, argv, &pms);
	if (ft_parse(&pms, 1) != OK)
		return (1);
	ft_checker(&pms);
	ft_clean_exit(&pms);
	return (0);
}
