/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:13:59 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/16 22:33:13 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	handle_range(long sum, int sign)
{
	if (sum <= 2147483647 && sum >= -2147483648)
		return (sum);
	else if (sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	long	sum;
	int		sign;
	int		found;

	sum = 0;
	sign = 1;
	found = 1;
	while ((*str == '\f' || *str == '\t' || *str == ' ' || \
			*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && found)
	{
		if (*str >= '0' && *str <= '9')
			sum = sum * 10 + *str - '0';
		else
			found = 0;
		str++;
	}
	return (handle_range(sum * sign, sign));
}
