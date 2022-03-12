/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:28:15 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/03/12 07:15:48 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_server_ready = 1;

static void	send_symbol(int pid, unsigned char symbol)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count < 8)
	{
		if (g_server_ready == 1)
		{
			g_server_ready = 0;
			if (symbol << bit_count & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_count++;
			usleep(100);
		}
	}
}

static void	send_string(char *pid, char *message)
{
	int	process_id;

	process_id = ft_atoi(pid);
	while (*message)
	{
		send_symbol(process_id, (unsigned char)*message);
		message++;
	}
	send_symbol(process_id, '\0');
}

static void	sig_handler_client(int signal)
{
	static int	bits_counter = 0;

	if (signal == SIGUSR1)
	{
		g_server_ready = 1;
		bits_counter++;
	}
	else if (signal == SIGUSR2)
	{
		ft_putnbr(bits_counter / 8);
		write(1, " bytes received.\n", 17);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig_act_client;
	int					string_len;

	if (ac != 3)
		return (write(1, "Incorrect number of arguments", 30));
	string_len = ft_strlen(av[2]);
	sig_act_client.sa_handler = sig_handler_client;
	sig_act_client.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_act_client, NULL);
	sigaction(SIGUSR2, &sig_act_client, NULL);
	ft_putnbr(string_len);
	write(1, " bytes sent.\n", 13);
	send_string(av[1], av[2]);
	return (0);
}
