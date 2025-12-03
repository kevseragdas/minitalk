/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:44:06 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/03 18:20:44 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_server	g_var;

static void	action(int signal, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (signal == SIGUSR2)
		g_var.chr = g_var.chr | (1 << (7 - g_var.bit_counter));
	g_var.bit_counter++;
	if (g_var.bit_counter == 8)
	{
		write(1, &g_var.chr, 1);
		g_var.bit_counter = 0;
		g_var.chr = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	g_var.bit_counter = 0;
	g_var.chr = 0;
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
