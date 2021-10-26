/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:05:51 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/16 19:41:50 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	memory = (void *)malloc(count * size);
	if (memory)
		ft_bzero(memory, count * size);
	return (memory);
}
