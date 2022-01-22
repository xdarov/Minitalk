/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:45:53 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/22 16:55:40 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(char *str, int ser_pid)
{
	int				i;
	unsigned int	ch;

	while (1)
	{
		i = 1;
		ch = (int)*str;
		while (i < 256)
		{
			if (ch & i)
				kill(ser_pid, SIGUSR1);
			else
				kill(ser_pid, SIGUSR2);
			i <<= 1;
			pause();
			usleep(150);
		}
		if (!*str)
			break ;
		str++;
	}
}

void	client_handler(int sig)
{
	static long	count;

	if (sig == SIGUSR1)
		count++;
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("bit sent: ", 1);
		ft_putnbr_fd(count, 1);
		ft_putchar_fd('\n', 1);
		count = 0;
	}
}

void	signal_ident(int sig, pid_t *pid)
{
	static int				i;
	static unsigned char	ch;
	static int				and;

	ch >>= 1;
	ch |= sig << 7;
	if (++i == 8)
	{
		write(1, &ch, 1);
		if (!ch)
			write(1, "\n", 1);
		if (!ch)
			and = 1;
		i = 0;
		ch = 0;
	}
	usleep(100);
	kill(*pid, SIGUSR1);
	if (and)
	{
		usleep(100);
		kill(*pid, SIGUSR2);
		*pid = 0;
		and = 0;
	}
}

void	server_handler(int sig, siginfo_t *siginfo, void *null)
{
	static pid_t	pid;

	null = NULL;
	if (!pid)
		pid = siginfo->si_pid;
	else if (pid && pid != siginfo->si_pid)
		return ;
	if (sig == SIGUSR1)
		signal_ident(1, &pid);
	else if (sig == SIGUSR2)
		signal_ident(0, &pid);
}
