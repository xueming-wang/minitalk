/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:43:05 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/20 17:15:51 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

static void	handle_sig(int sig)
{
	static unsigned int		i = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c += 1 << i;
	++i;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid == -1)
		return (-1);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	ft_putstr("PID = ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
