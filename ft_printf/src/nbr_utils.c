/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:08:15 by avoltorb          #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_digits_base(t_num_params num_params, t_conv_params params)
{
	int					j;
	unsigned long long	n;
	unsigned long long	base_len;

	base_len = (unsigned long long)num_params.base_len;
	j = 1;
	if (params.flag == 'p')
	{
		n = num_params.print_num;
		while (n >= base_len)
		{
			n /= base_len;
			j++;
		}
	}
	else
	{
		n = num_params.print_num;
		while (n >= base_len)
		{
			n /= base_len;
			j++;
		}
	}
	return (j);
}

void	ft_put_nbr(t_conv_params params, t_num_params num_params)
{
	unsigned long long		num;
	unsigned long long		base_len;
	int						num_len;
	char					*base;

	num = num_params.print_num;
	base_len = (unsigned long long)num_params.base_len;
	base = num_params.base;
	num_len = num_params.num_len;
	ft_put_plus_minus(params, num_params);
	if (!(num == 0 && num_len == 1))
	{
		ft_put_prefix_zeros(params, num_params);
		if (num >= base_len)
			ft_putnbr_base(num / base_len, base_len, base);
		write(1, &base[num % base_len], 1);
	}
	else
		ft_put_zero(params, num_params);
	params.width_zero = 0;
}

void	ft_putnbr_base(unsigned long long num,
						unsigned long long base_len,
						char *base)
{
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base_len, base);
	write(1, &base[num % base_len], 1);
}

void	ft_put_zero(t_conv_params params, t_num_params num_params)
{
	int	len;

	len = params.right_width - (num_params.num_len + num_params.neg);
	if (params.left_width + params.right_width == -2
		|| params.space || params.plus || params.sharp
		|| params.right_width == 1
		|| (params.left_width == -1 && params.right_width > 0 && params.minus)
		|| (params.minus
			&& !params.dot && params.left_width + params.right_width <= -1))
		write(1, "0", 1);
	else if ((params.minus && !params.dot)
		|| (params.left_width + params.right_width == -2 && !params.minus)
		|| (params.width_zero))
		ft_put_chars(params.right_width - 1, ' ');
	else if ((params.dot && params.right_width > 0 && params.left_width == -1)
		|| (params.right_width > 0 && params.left_width == -1))
		ft_put_chars(params.right_width, '0');
}

int	ft_max(int a, int b)
{
	if (a > b && a > 0)
		return (a);
	else if (b > 0)
		return (b);
	else
		return (0);
}
