/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:15:42 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_count_printed_str(t_conv_params params, char *str)
{
	int	right;
	int	left;
	int	len;
	int	return_len;

	len = ft_strlen(str, '\0');
	if (params.space && params.left_width > 0 && len > 0)
		return_len = params.space;
	else
		return_len = 0;
	right = params.right_width - len;
	left = params.left_width - len;
	if (params.right_width == -1 || (params.right_width > 0 && !params.dot))
		return_len += ft_count_nonwidth(params, len, right);
	else if (left >= right)
		return_len += ft_count_left_greater(params, len, left, right);
	else if (params.right_width > 0 && params.dot)
		return_len += ft_count_right_dot(params, len, left, right);
	else if (right > left)
		return_len += ft_count_right_greater(params, len, left, right);
	if (return_len == params.space && params.right_width > 0)
		return_len += len;
	return (return_len);
}

int	ft_count_right_dot(t_conv_params params, int len, int left, int right)
{
	if (right > 0 && params.minus && params.left_width > params.right_width)
		return (len + params.left_width - params.right_width);
	else if (params.minus && left > 0)
		return (left + len);
	else if (right > 0)
		return (len);
	else
		return (params.right_width);
}

int	ft_count_left_greater(t_conv_params params, int len, int left, int right)
{
	if (left >= right && right > 0)
		return (len);
	else
		return (params.left_width);
}

int	ft_count_right_greater(t_conv_params params, int len, int left, int right)
{
	if (right > 0 || (params.right_width < 0 || (params.minus && !params.dot))
		|| (params.space && params.right_width == 0 && right > left))
		return (len);
	else
		return (params.right_width);
}

int	ft_count_nonwidth(t_conv_params params, int len, int right)
{
	if (right > 0)
		return (params.right_width);
	else
		return (len);
}
