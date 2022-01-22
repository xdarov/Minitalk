/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorina <pcorina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:37:08 by pcorina           #+#    #+#             */
/*   Updated: 2022/01/22 18:16:07 by pcorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

void	signal_ident(int sig, pid_t *pid);
void	server_handler(int sig, siginfo_t *siginfo, void *null);
void	client_handler(int sig);
void	send_signal(char *str, int ser_pid);
#endif