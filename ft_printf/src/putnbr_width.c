/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:44:30 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_spminus(int count, int toprint, int isminus)
{
	if (toprint == isminus)
		ft_put_chars(count, ' ');
}

void	ft_put_width_nbr(t_conv_params params, t_num_params num_params)
{
	ft_put_prefix_space(params, num_params);
	if (params.right_width != -1 && params.left_width != -1)
		ft_put_double_width_num(params, num_params);
	else if (params.left_width == -1)
		ft_put_single_width_num(params, num_params);
}

void	ft_put_single_width_num(t_conv_params params, t_num_params num_params)
{
	int	len;

	len = params.right_width - (num_params.num_len + num_params.neg);
	if (!params.dot && !params.zero)
	{
		if (!params.minus)
			ft_put_chars(len, ' ');
		ft_put_nbr(params, num_params);
		if (params.minus)
			ft_put_chars(len, ' ');
	}
	else
	{
		if (params.dot)
			len += num_params.neg;
		ft_put_nbr(params, num_params);
	}
}

void	ft_put_double_width_num(t_conv_params params, t_num_params num_params)
{
	int	left;
	int	right;

	left = params.left_width - num_params.num_len;
	right = params.right_width - num_params.num_len;
	if (left > right && left >= 0)
	{
		if (right > 0)
			ft_put_spminus(left - (right + num_params.neg), 0, params.minus);
		else if (num_params.num == 0)
			ft_put_spminus(params.left_width, 0, params.minus);
		else
			ft_put_spminus(left - num_params.neg, 0, params.minus);
	}
	else if (((right >= left) && right > 0) && (num_params.num == 0))
		ft_put_chars(right + 1, '0');
	ft_put_nbr(params, num_params);
	if (right > 0)
		ft_put_spminus(left - (right + num_params.neg), 1, params.minus);
	else if (right <= 0 && left > 0 && num_params.num == 0)
		ft_put_spminus(left + 1 - num_params.neg, 1, params.minus);
	else if (right <= 0 && left > 0)
		ft_put_spminus(left - num_params.neg, 1, params.minus);
}

void	ft_put_plus_minus(t_conv_params params, t_num_params num_params)
{
	if (num_params.neg)
		write(1, "-", 1);
	else if (params.plus && ft_strchr("di", params.flag))
		write(1, "+", 1);
}
