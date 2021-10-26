/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:25:10 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/21 17:37:49 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*handle_min(char *str)
{
	int		i;
	char	*num;

	num = "-2147483648";
	i = -1;
	while (num[++i])
		str[i] = num[i];
	return (str);
}

char	*handle_nu(int n, int pw, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	else if (n == -2147483648)
		return (handle_min(str));
	else
	{
		if (n < 0)
		{
			str[0] = '-';
			n *= -1;
		}
		while (n > 0)
		{
			str[pw] = 48 + (n % 10);
			n /= 10;
			pw--;
		}
		return (str);
	}
}

char	*ft_itoa(int n)
{
	int		pw;
	char	*str;

	pw = len(n);
	str = (char *)malloc(sizeof(char) * (pw + 1));
	if (!str)
		return (NULL);
	str[pw--] = '\0';
	return (handle_nu(n, pw, str));
}
