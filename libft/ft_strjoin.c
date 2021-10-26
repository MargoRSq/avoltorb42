/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:46:02 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/16 20:23:54 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*memory;

	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		memory = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
		if (!memory)
			return (NULL);
		i = -1;
		while (s1[++i])
			memory[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			memory[s1len + i] = s2[i];
		}
		memory[s1len + s2len] = '\0';
		return (memory);
	}
	return (NULL);
}
