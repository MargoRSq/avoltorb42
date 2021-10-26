/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:36:22 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/21 17:41:08 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *str, const char *s, size_t len, unsigned int start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		slen;

	if (s)
	{
		slen = ft_strlen(s);
		if (len > slen)
			len = slen;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		return (fill_str(str, s, len, start));
	}
	return (NULL);
}
