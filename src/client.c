/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/11 14:10:05 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "garbadge.h"
#include "get_next_line.h"
#include <colors.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	char	*str;
	int		i;
	char	*line;
	int		pid;

	line = get_next_line(1);
	pid = ft_atoi(line);
	i = 42;
	while (i)
	{
		if (i >> 7 & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100 * 1000);
		i = i << 1;
	}
	return (1);
}
