/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 10:11:36 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_atoi_fill(int *i, t_conv_params *params)
{
	int			sum;
	int			j;
	int			found;

	sum = 0;
	found = 1;
	j = 0;
	while ((((params->str[j] <= '0' || params->str[j] > '9')
				&& params->str[j] != params->flag)
			&& params->str[j]))
	{
		ft_fill_conv_params(params, j);
		j++;
		(*i)++;
	}
	ft_fetch_width(params, &j, i);
}

void	ft_fetch_width(t_conv_params *params, int *j, int *i)
{
	int	found;
	int	sum;

	sum = 0;
	found = 1;
	while (params->str[*j] != params->flag && params->str[*j] != '.'
		&&found && params->str[*j])
	{
		if (params->str[*j] >= '0' && params->str[*j] <= '9')
			sum = sum * 10 + params->str[*j] - '0';
		else
			found = 0;
		(*j)++;
		(*i)++;
	}
	if (params->right_width < 0)
		params->right_width = sum;
	else
	{
		params->left_width = params->right_width;
		params->right_width = sum;
	}
}

void	ft_fill_conv_params(t_conv_params *params, int j)
{
	const char	*str;

	str = params->str;
	if (str[j] == '+')
		params->plus = TRUE;
	else if (str[j] == '0')
		params->zero = TRUE;
	else if (str[j] == '.' && str[j + 1] == params->flag)
	{
		params->width_zero = TRUE;
		params->dot = TRUE;
	}
	else if (str[j] == '.')
		params->dot = TRUE;
	else if (str[j] == '#')
		params->sharp = TRUE;
	else if (str[j] == '-')
		params->minus = TRUE;
	else if (str[j] == ' ' && j == 0)
		params->space = TRUE;
}
