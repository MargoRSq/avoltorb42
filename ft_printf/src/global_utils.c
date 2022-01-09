/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:12:57 by avoltorb          #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_strlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	ft_strchr(const char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	return (c);
}

char	ft_flagschr(char *flags, const char *str)
{
	int		j;
	char	flag;

	if (!str)
		return (0);
	j = 0;
	flag = 0;
	flag = ft_search_flag(&j, flags, str);
	return (flag);
}

int	ft_search_flag(int *i, char *flags, const char *str)
{
	char	flag;

	flag = 0;
	while (!flag)
	{
		flag = ft_strchr(flags, str[*i]);
		if (str[*i] == '\0')
			return (0);
		(*i)++;
	}
	return (flag);
}

int	ten_pow(int width)
{
	int	i;

	i = 1;
	while ((width / 10) > 0)
	{
		width /= 10;
		i++;
	}
	return (i);
}
