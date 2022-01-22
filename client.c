/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:28 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/22 18:27:37 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					ser_pid;

	if (argc == 3)
	{
		sa.sa_handler = client_handler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		ser_pid = ft_atoi(argv[1]);
		if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
			return (write(2, "Sigaction error\n", 16));
		send_signal(argv[2], ser_pid);
	}
	return (0);
}
