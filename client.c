/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagdas <kagdas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:43:51 by kagdas            #+#    #+#             */
/*   Updated: 2025/12/03 18:47:42 by kagdas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_answ_came = 0;

static void	client_handler(int signal)
{
	(void) signal;
	g_answ_came = 1;
}

static void	send_char(int pid, char c)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		g_answ_came = 0;
		if (((c >> bit_index) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_answ_came == 0)
			pause();
		bit_index--;
	}
}

static int	pid_controller(char *s)
{
	int	count;
	int	pid;

	count = ft_count(s);
	if (count > 7)
	{
		write(2, "Invalid pid!", 13);
		exit(1);
	}
	pid = ft_atoi(s);
	if (pid <= 0 || pid >= 4194304)
	{
		write(2, "Invalid pid!", 13);
		exit (1);
	}
	return (pid);
}

int	main(int ac, char **arg)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = pid_controller(arg[1]);
		signal(SIGUSR1, client_handler);
		i = 0;
		while (arg[2][i])
		{
			send_char(pid, arg[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		write(2, "Missing arguments!", 19);
		return (1);
	}
	return (0);
}
