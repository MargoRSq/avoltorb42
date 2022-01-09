/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:21:42 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_count_zero(t_conv_params params, t_num_params num_params)
{
	if (num_params.num == 0 && params.flag == 'p' && params.right_width > 3)
		return (params.right_width);
	else if (num_params.num == 0 && params.flag == 'p')
		return (3);
	if (num_params.num == 0 && params.right_width > 0)
		return (ft_max(params.right_width, params.left_width));
	else if (num_params.num == 0 && params.left_width > 0)
		return (params.left_width);
	else if (num_params.num == 0 && \
			(params.plus || params.space))
		return (2);
	else if (num_params.num == 0 && ((params.minus && !params.dot) || \
	(ft_strchr("xX", params.flag) && params.sharp)))
		return (1);
	else if (num_params.num == 0 && \
		(params.width_zero || params.right_width == 0))
		return (0);
	return (1);
}

int	ft_count_nonzero(t_conv_params params, t_num_params num_params,
					int right, int left)
{
	int	printed_len;

	if (params.plus || num_params.neg)
		num_params.num_len += 1;
	printed_len = num_params.num_len;
	if (num_params.num_len > params.left_width
		&& num_params.num_len > params.right_width)
		printed_len = num_params.num_len;
	else if (right >= left && right > 0)
	{
		printed_len = params.right_width;
		if (params.dot && (num_params.neg || params.plus))
			printed_len++;
	}
	else if (left * right > 0)
		printed_len = ft_max(params.left_width, params.right_width);
	else if (left <= 0 && right > 0)
		printed_len = params.right_width;
	else if (left > 0 && right <= 0)
		printed_len = params.left_width;
	else
		printed_len = num_params.num_len;
	if (params.space && !num_params.neg)
		printed_len++;
	return (printed_len);
}
