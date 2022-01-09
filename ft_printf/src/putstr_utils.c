/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:35:07 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_str(t_conv_params params, char *str)
{
	int	space;
	int	right;
	int	left;
	int	len;

	len = ft_strlen(str, '\0');
	right = params.right_width - len;
	left = params.left_width - len;
	space = ft_print_space_string(params, len);
	if (params.right_width == -1 || (params.right_width > 0 && !params.dot))
		ft_put_nonwidth(params, str, right);
	else if (params.right_width > 0 && params.dot)
		ft_put_dot(params, str, left, right);
	else if (left >= right)
		ft_put_left_greater(params, str, left, right);
	else if (right > left)
		ft_put_right_greater(params, str, left, right);
	else if (right < 0)
		write(1, str, len);
}

int	ft_print_space_string(t_conv_params params, int len)
{
	int	space;

	space = 0;
	if (params.space && params.left_width > 0 && len > 0)
	{
		write(1, " ", 1);
		space = 1;
	}
	return (space);
}

int	ft_print_nonzero(t_conv_params params, int len, char *str)
{
	int	count;

	count = len;
	if ((params.minus && params.left_width >= len) || \
		(params.flag == 's' && params.left_width >= len))
	{
		if (params.minus)
			write(1, str, len);
		if (params.left_width > len && (params.minus || !params.dot))
		{
			while (count < params.left_width)
			{
				count++;
				write(1, " ", 1);
			}
		}
		else
			count = 0;
	}
	if (!params.minus || (params.minus && params.left_width == -1))
		write(1, str, len);
	if (params.left_width > len && !params.dot)
		return (params.left_width);
	else
		return (len);
}

int	ft_print_double_width(t_conv_params params, int len, char *str)
{
	int	return_len;
	int	printed;

	printed = 0;
	if (params.right_width > len)
	{
		ft_put_chars(params.right_width - len, ' ');
		write(1, str, len);
	}
	else
		write(1, str, params.right_width);
	return_len = len;
	if (params.left_width > len)
	{
		if (params.minus)
			write(1, str, len);
		return_len = params.left_width;
		while (params.left_width-- > params.right_width)
			write(1, " ", 1);
	}
	if (!params.minus)
		write(1, str, len);
	return (return_len);
}
