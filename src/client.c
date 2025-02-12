/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/12 12:15:25 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "garbadge.h"
#include <colors.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_char(int pid, int c)
{
	int	o;

	o = 7;
	while (o >= 0)
	{
		if ((c >> o) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		o--;
		usleep(1);
	}
	usleep(1);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2] && av[2][i])
	{
		send_char(pid, av[2][i++]);
	}
	send_char(pid, 0);
	return (1);
}
