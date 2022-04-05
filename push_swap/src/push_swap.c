/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:04:02 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:36:32 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_pms	pms;

	ft_init(argc, argv, &pms);
	if (ft_parse(&pms, 0) != OK)
		return (1);
	ft_sort(&pms);
	ft_clean_exit(&pms);
	return (0);
}
