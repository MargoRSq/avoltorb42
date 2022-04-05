/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:52:27 by avoltorb          #+#    #+#             */
/*   Updated: 2022/04/04 14:51:54 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atoi(const char *str)
{
	long	sum;
	int		sign;
	int		found;

	sum = 0;
	sign = 1;
	found = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	if (sum > MAXINT || sum < MININT)
		return ((long) MAXINT + 1);
	return (sum * sign);
}

void	ft_insertion_sort(t_pms *pms)
{
	int	i;
	int	j;
	int	key;

	i = 0;
	while (++i < pms->ac)
	{
		key = pms->arr[i];
		j = i - 1;
		while (j >= 0 && pms->arr[j] > key)
		{
			pms->arr[j + 1] = pms->arr[j];
			j = j - 1;
		}
		pms->arr[j + 1] = key;
	}
}

int	ft_parse_av(t_pms *pms)
{
	int		i;
	long	tmp;
	t_node	*new;

	pms->arr = (int *)malloc(sizeof(int) * pms->ac + 1);
	if (!pms->arr)
		return (1);
	i = -1;
	while (++i < pms->ac)
	{
		tmp = ft_atoi(pms->av[i]);
		if (tmp == (long)MAXINT + 1)
		{
			pms->ac = i;
			return (write(1, "Error\n", 6));
		}
		pms->arr[i] = (int)tmp;
		new = ft_lstnew((int)tmp, i);
		ft_lstadd_back(&(pms->begin_a), new);
	}
	return (0);
}

int	ft_clean_exit(t_pms *pms)
{
	int		i;

	ft_free_stack('A', pms);
	ft_free_stack('B', pms);
	if (pms->arr)
		free(pms->arr);
	i = -1;
	if (pms->flag_unpacked)
		while (pms->av[++i])
			free(pms->av[i]);
	free(pms->av);
	return (1);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 && *s2)
	{
		if (!*s1 && !*s2)
			return (0);
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
