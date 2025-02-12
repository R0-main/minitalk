/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/12 11:51:15 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include "garbadge.h"
#include <colors.h>
#include <signal.h>
#include <stdlib.h>

char	g_byte = -1;

void	handle_0(int sig)
{
	g_byte = 0;
}

void	handle_1(int sig)
{
	g_byte = 1;
}

bool	received_char(char **str, char *c, int *o)
{
	char	*t;
	char	*old_str;

	t = malloc(2);
	if (!t)
		return (free(*str), true);
	t[0] = *c;
	t[1] = 0;
	old_str = *str;
	*str = ft_strjoin(*str, t);
	if (!str)
		return (free(old_str), free(t), true);
	free(old_str);
	free(t);
	if (*c == 0)
	{
		ft_fprintf(1, "%s\n", *str);
		*str = ft_strdup("");
	}
	*o = 7;
	*c = 0;
	return (false);
}

int	main(void)
{
	char	*str;
	char	c;
	int		o;

	signal(SIGUSR1, handle_0);
	signal(SIGUSR2, handle_1);
	ft_fprintf(STDOUT_FILENO, CYN "server " RED "PID" RESET " : %d\n",
		getpid());
	c = 0;
	o = 7;
	str = ft_strdup("");
	while (1)
	{
		if (g_byte != -1)
		{
			c |= (g_byte << o);
			o--;
			g_byte = -1;
			if (o == -1)
				received_char(&str, &c, &o);
		}
	}
	free(str);
	return (1);
}
