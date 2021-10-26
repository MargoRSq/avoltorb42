/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:48:03 by svyatoslav        #+#    #+#             */
/*   Updated: 2021/10/19 17:48:05 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nb < 10 && nb >= 0)
		ft_putchar_fd(nb + '0', fd);
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
		if (nb < 0)
			ft_putchar_fd('-', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nb * -1, fd);
	}
}
