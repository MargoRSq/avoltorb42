/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:06 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/10 11:29:42 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <zconf.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		ready;
	int		pid;
	int		index;
	int		nulls;
	char	symbol;
}	t_flag;

long long			ft_atoi(const char *str);
void				ft_putnbr(int n);
int					ft_strlen(const char *str);

#endif