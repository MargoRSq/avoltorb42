/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:45 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/10 11:29:12 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_flag	g_status;

static void	storage_reset(void)
{
	g_status.index = 0;
	g_status.symbol = 0;
	g_status.nulls = 0;
}

static void	sig_handler_server(int signal, siginfo_t *siginfo, void *context)
{
	g_status.ready = 0;
	(void)context;
	if (g_status.pid == 0 || g_status.pid != siginfo->si_pid)
	{
		storage_reset();
		g_status.pid = siginfo->si_pid;
	}
	g_status.symbol = g_status.symbol | (signal == SIGUSR1);
	g_status.nulls += (signal == SIGUSR2);
	g_status.index++;
	if (g_status.index == 8)
	{
		if (g_status.nulls == 8)
		{
			kill(g_status.pid, SIGUSR2);
			write(1, "\n", 1);
			return ;
		}
		write(1, &g_status.symbol, 1);
		storage_reset();
	}
	else
		g_status.symbol = g_status.symbol << 1;
	g_status.ready = 1;
}

int	main(void)
{
	struct sigaction	sig_act_server;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sig_act_server.sa_sigaction = sig_handler_server;
	sig_act_server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_act_server, NULL);
	sigaction(SIGUSR2, &sig_act_server, NULL);
	while (1)
	{
		if (g_status.ready == 0)
			continue ;
		else
			g_status.ready = 0;
		kill(g_status.pid, SIGUSR1);
	}
	return (0);
}
