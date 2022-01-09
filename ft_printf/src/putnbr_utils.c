/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:39:42 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_isneg(t_conv_params params, t_num_params *num_params)
{
	if ((num_params->num < 0 && num_params->unsgnd == 0) && params.flag != 'p')
	{
		num_params->neg = 1;
		num_params->print_num = (unsigned int)(num_params->num * -1);
	}
	else if ((num_params->num < 0 && num_params->unsgnd == 0) \
			|| params.flag == 'p')
	{
		num_params->print_num = (unsigned long long)(num_params->num);
	}
	else
		num_params->print_num = (unsigned int)(num_params->num);
}

void	ft_base(t_conv_params params, t_num_params *num_params)
{
	if (num_params->hex)
	{
		num_params->base_len = 16;
		if (params.flag == 'x' || params.flag == 'p')
			num_params->base = "0123456789abcdef";
		else
			num_params->base = "0123456789ABCDEF";
	}
	else
	{
		num_params->base_len = 10;
		num_params->base = "0123456789";
	}
}

int	ft_count_printed_len(t_conv_params params, t_num_params num_params)
{
	int	printed_len;
	int	left;
	int	right;

	left = params.left_width - num_params.num_len;
	right = params.right_width - num_params.num_len;
	if (num_params.num == 0)
		printed_len = ft_count_zero(params, num_params);
	else
	{
		if ((ft_strchr("xX", params.flag) && params.sharp)
			|| params.flag == 'p')
			printed_len = 2;
		printed_len = ft_count_nonzero(params, num_params, right, left);
	}
	return (printed_len);
}
