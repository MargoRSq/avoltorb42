/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:59:11 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/21 17:05:04 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*start;

	start = s;
	while (*s)
		s++;
	while (s >= start)
	{
		if ((unsigned char)*s-- == (unsigned char)c)
			return (s + 1);
	}
	return (NULL);
}
