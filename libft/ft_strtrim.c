/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:37:54 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/18 16:37:55 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*mstring;
	size_t	slen;

	if (!s || !set)
		return (NULL);
	while (*s && ft_strchr((char *)set, *s))
		s++;
	slen = ft_strlen(s);
	while (slen && ft_strchr((char *)set, s[slen]))
		slen--;
	mstring = ft_substr((char *)s, 0, slen + 1);
	return (mstring);
}
