/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:43:40 by avoltorb          #+#    #+#             */
/*   Updated: 2022/01/03 14:26:12 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar_move(int *i, const char *c_ptr)
{
	write(1, c_ptr, 1);
	(*i)++;
	return (1);
}

int	ft_handle_conversions(int *i, const char *str, char flag, va_list *args)
{
	int				len;
	t_conv_params	params;

	params = (struct conversion_params){.flag = flag, .args = args, \
			.right_width = -1, .left_width = -1};
	ft_fill_params(&params, str);
	len = 0;
	if (flag == 'c')
		len = ft_putchar(params);
	else if (flag == 's')
		len = ft_putstr(params);
	else if (flag == '%')
		len = ft_putprocent();
	else if (flag == 'd' || flag == 'i')
		len = ft_putnbr(params, 0, 0);
	else if (flag == 'u')
		len = ft_putnbr(params, 1, 0);
	else if (flag == 'x' || flag == 'X')
		len = ft_putnbr(params, 1, 1);
	else if (flag == 'p')
		len = ft_putnbr(params, 0, 1);
	(*i) += params.skip + 1;
	return (len);
}

void	ft_fill_params(t_conv_params *params, const char *str)
{
	int	i;

	params->skip = ft_strlen((char *)str, params->flag) + 1;
	i = 0;
	while (str[i] != params->flag && str[i])
	{
		params->str = &str[i];
		ft_atoi_fill(&i, params);
	}
}
