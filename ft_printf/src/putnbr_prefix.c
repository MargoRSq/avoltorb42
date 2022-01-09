/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:47:07 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_prefix_space(t_conv_params params, t_num_params num_params)
{
	if (params.space && !num_params.neg)
		ft_put_chars(1, ' ');
	if ((ft_strchr("xX", params.flag) && params.sharp && \
		num_params.num != 0))
	{
		write(1, "0", 1);
		if (params.flag == 'x')
			write(1, &"x", 1);
		else if (params.flag == 'X')
			write(1, &"X", 1);
	}
}

void	ft_put_prefix_zeros(t_conv_params params, t_num_params num_params)
{
	int	left;
	int	right;
	int	len;

	left = params.left_width - num_params.num_len;
	right = params.right_width - num_params.num_len;
	len = params.right_width - (num_params.num_len + num_params.neg);
	if (params.flag == 'p')
		write(1, "0x", 2);
	if (!params.dot && params.zero)
		ft_put_chars(len, '0');
	else if (((params.dot || params.left_width > 0) \
		&& ((left < 0 && right > 0) || (left > right && left >= 0) \
		|| ((right >= left) && right > 0 && num_params.num != 0))) \
		|| (params.zero && right > 0))
		ft_put_chars(right, '0');
}
