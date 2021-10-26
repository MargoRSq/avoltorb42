/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:04:37 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/16 22:33:13 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		i;
	size_t		reslen;

	d = dst;
	s = src;
	dlen = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > dlen)
	{
		reslen = (dlen + ft_strlen(src));
		while (i + dlen + 1 < dstsize && s[i])
		{
			d[i + dlen] = s[i];
			i++;
		}
		d[i + dlen] = '\0';
	}
	else
		reslen = (dstsize + ft_strlen(src));
	return (reslen);
}
