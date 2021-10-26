/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:41:48 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/22 14:41:24 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, const char *needle, size_t len)
{
	int			n;
	size_t		h;

	if (!(*needle))
		return (haystack);
	if (len == 0)
		return (NULL);
	h = 0;
	while (haystack[h] && h < len)
	{
		n = 0;
		if (haystack[h] == needle[n])
		{
			while (n + h < len && haystack[n + h] == needle[n])
			{
				n++;
				if (!needle[n])
					return ((char *)&haystack[h]);
			}
		}
		h++;
	}
	return (NULL);
}
