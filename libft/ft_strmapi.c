/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:48:05 by margo             #+#    #+#             */
/*   Updated: 2021/10/20 15:50:55 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*strmemory;

	if (!s || !f)
		return (NULL);
	strmemory = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!strmemory)
		return (NULL);
	i = -1;
	while (s[++i])
		strmemory[i] = f(i, s[i]);
	strmemory[i] = '\0';
	return (strmemory);
}
