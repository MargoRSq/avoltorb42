/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:05:51 by avoltorb          #+#    #+#             */
/*   Updated: 2022/03/04 11:04:39 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

void	ft_strncpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while ((dest && src) && (dest[i] || src[i]) && len--)
	{
		dest[i] = src[i];
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *cache, char *buf)
{
	int		clen;
	int		blen;
	char	*str;

	if (cache == NULL)
	{
		cache = (char *)malloc(sizeof(char));
		if (!cache)
			return (NULL);
		cache[0] = '\0';
	}
	clen = ft_strlen(cache);
	blen = ft_strlen(buf);
	str = (char *)malloc(sizeof(char) * (clen + blen + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, cache, clen);
	ft_strncpy(&str[clen], buf, blen);
	str[clen + blen] = '\0';
	free(cache);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}
