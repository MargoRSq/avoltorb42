/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:04:48 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 11:04:49 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_strnumber(const char *s, char sep)
{
	int	i;
	int	flag;
	int	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != sep && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == sep && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*fillmemory(const char *str, char *result, int count, int *j)
{
	int	i;

	if (result)
	{
		i = 0;
		while (i < count)
		{
			result[i] = str[*j];
			i++;
			(*j)++;
		}
		result[i] = '\0';
	}
	return (result);
}

static char	*strinit(const char *s, char sep, int *j)
{
	int		tmp;
	int		count;
	char	*result;

	while (s[*j] == sep && s[*j])
		(*j)++;
	tmp = *j;
	count = 0;
	while (s[tmp] != sep && s[tmp])
	{
		count++;
		tmp++;
	}
	result = (char *)malloc(sizeof(char) * (count + 1));
	return (fillmemory(s, result, count, j));
}

static char	**free_dmalloc(char **dmemory)
{
	int	i;

	i = -1;
	while (dmemory[++i])
		free(dmemory[i]);
	free(dmemory);
	return (NULL);
}

char	**ft_split(char const *s, char sep)
{
	int		i;
	int		j;
	int		wcount;
	char	**dmemory;

	if (!s)
		return (NULL);
	wcount = ft_get_strnumber(s, sep);
	dmemory = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!dmemory)
		return (NULL);
	dmemory[wcount] = NULL;
	i = 0;
	j = 0;
	while (i < wcount)
	{
		dmemory[i] = strinit(s, sep, &j);
		if (!dmemory[i])
			return (free_dmalloc(dmemory));
		i++;
	}
	return (dmemory);
}
