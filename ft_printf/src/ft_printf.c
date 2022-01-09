/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:56:40 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/01/03 23:04:27 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;
	int		i;
	char	flag;

	if (!str)
		return (-1);
	printed = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = ft_flagschr("cspdiuxX%", &str[i + 1]);
			if (str[i] == '%' && str[i + 1] == '%')
				printed += ft_handle_conversions(&i, &str[i + 1], '%', &args);
			else if (str[i + 1] && flag)
				printed += ft_handle_conversions(&i, &str[i + 1], flag, &args);
		}
		else
			printed += ft_putchar_move(&i, &str[i]);
	}
	va_end(args);
	return (printed);
}

// printf("%12.7s 0\n", "42");
//     ft_printf("%12.7s 0\n", "42");