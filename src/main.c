/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:57:55 by rguigneb          #+#    #+#             */
/*   Updated: 2025/02/11 12:59:55 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include <stdlib.h>
#include <colors.h>

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	ft_fprintf(STDOUT_FILENO, RED "fqwffqfwqfq\n" RESET);
	return (EXIT_SUCCESS);
}

