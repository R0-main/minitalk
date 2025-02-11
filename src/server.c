/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/11 14:01:44 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "garbadge.h"
#include <colors.h>
#include <signal.h>
#include <stdlib.h>

char		byte;

void	handle_0(int sig)
{
	byte = 0;
}

void	handle_1(int sig)
{
	byte = 1;
}

int	main(void)
{
	char	*str;
	int		i;

	signal(SIGUSR1, handle_0);
	signal(SIGUSR2, handle_1);
	ft_fprintf(STDOUT_FILENO, CYN "server " RED "PID" RESET " : %d\n",
		getpid());
	while (1)
	{
		i = -1;
		if (byte != -1)
		{
			ft_fprintf(1, "%d\n", byte);
			byte = -1;
		}
	}
	return (1);
}
