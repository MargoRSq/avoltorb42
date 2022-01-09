/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:36:58 by avoltorb          #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar(t_conv_params params)
{
	char	c;
	int		return_len;

	c = va_arg(*(params.args), int);
	if (params.minus)
		write(1, &c, 1);
	ft_put_chars(params.right_width - 1, ' ');
	if (!params.minus)
		write(1, &c, 1);
	if (params.right_width > 0)
		return_len = params.right_width;
	else
		return_len = 1;
	return (return_len);
}

int	ft_putstr(t_conv_params params)
{
	char	*str;
	int		return_len;

	return_len = 0;
	str = va_arg(*(params.args), char *);
	if (!str)
		str = "(null)";
	return_len = ft_count_printed_str(params, str);
	ft_put_str(params, str);
	return (return_len);
}

int	ft_putprocent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putnbr(t_conv_params params, int unsd, int hex)
{
	t_num_params	num_params;
	int				return_len;
	int				prefix;

	num_params = (struct putnbr_params){.hex = hex, .unsgnd = unsd};
	if (params.flag != 'p')
		num_params.num = va_arg(*(params.args), int);
	else
		num_params.num = va_arg(*(params.args), unsigned long long int);
	ft_isneg(params, &num_params);
	ft_base(params, &num_params);
	prefix = 0;
	if (params.flag == 'p'
		|| (ft_strchr("xX", params.flag) && params.sharp && num_params.num))
		prefix = 2;
	num_params.num_len = ft_digits_base(num_params, params) + prefix;
	ft_put_width_nbr(params, num_params);
	return_len = ft_count_printed_len(params, num_params);
	return (return_len);
}
