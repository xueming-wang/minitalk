/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:43:02 by xuwang            #+#    #+#             */
/*   Updated: 2021/06/20 17:15:27 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minitalk.h"

static char	*ft_bina(char c)
{
	char	*bina;
	int		i;

	bina = malloc(sizeof(char) * 9);
	if (!bina)
		return (NULL);
	i = 7;
	while (i >= 0 && c >= 0)
	{
		if (c % 2 == 1)
			bina[i] = '1';
		else if (c % 2 == 0)
			bina[i] = '0';
		c = c / 2;
		i--;
	}
	bina[8] = '\0';
	return (bina);
}

static void	sig_bina(char c, int pid)
{
	int		i;
	char	*tmp;

	i = 7;
	tmp = ft_bina(c);
	while (i >= 0)
	{
		if (tmp[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep (100);
	}
	free(tmp);
}

static void	send_sig(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		sig_bina(s[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Error Argument\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr("Error PID\n");
		return (1);
	}
	send_sig(argv[2], pid);
	return (0);
}
