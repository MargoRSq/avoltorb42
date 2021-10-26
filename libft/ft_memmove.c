/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:11:24 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/15 19:12:41 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (s < d)
	{
		while (++i <= len)
		{
			d[len - i] = s[len - i];
		}
	}
	else
	{
		while ((d != NULL || s != NULL) && len--)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
