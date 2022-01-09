/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:01:03 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 14:25:56 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_put_nonwidth(t_conv_params params, char *str, int right)
{
	int	len;

	len = ft_strlen(str, '\0');
	if (right > 0)
	{
		if (!params.minus)
			ft_put_chars(right, ' ');
		write(1, str, len);
		if (params.minus)
			ft_put_chars(right, ' ');
	}
	else
		write(1, str, len);
}

void	ft_put_dot(t_conv_params params, char *str, int left, int right)
{
	int	len;

	len = ft_strlen(str, '\0');
	if (!params.minus)
		ft_put_chars(params.left_width - params.right_width, ' ');
	if (right > 0)
		write(1, str, len);
	else
		write(1, str, params.right_width);
	if (params.minus && params.left_width > params.right_width)
		ft_put_chars(params.left_width - params.right_width, ' ');
	else if (params.minus && left > 0)
		ft_put_chars(left, ' ');
}

void	ft_put_left_greater(t_conv_params params,
								char *str, int left, int right)
{
	int	len;

	len = ft_strlen(str, '\0');
	if (params.minus)
		ft_put_chars(left - right, ' ');
	if (right > 0)
		write(1, str, len);
	else
		write(1, str, params.right_width);
	if (!params.minus)
		ft_put_chars(left - right, ' ');
}

void	ft_put_right_greater(t_conv_params params,
								char *str, int left, int right)
{
	int	len;

	len = ft_strlen(str, '\0');
	if (right > 0 && right > left)
	{
		if (params.minus)
			ft_put_chars(right, ' ');
		write(1, str, len);
		if (!params.minus)
			ft_put_chars(right, ' ');
	}
	else if (params.right_width < 0 || (params.minus && !params.dot))
		write(1, str, len);
	else if (params.space && params.right_width == 0 && !params.dot)
		write(1, str, len);
	else
		write(1, str, params.right_width);
}
