/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:17:54 by emsoares          #+#    #+#             */
/*   Updated: 2023/01/06 10:33:25 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	bit;
	static char	c;

	if (signal == SIGUSR1)
		c = ((1 << bit) | c);
	if (signal == SIGUSR2)
		c = ((0 << bit) | c);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error! verify the input \n");
		return (0);
	}	
	ft_printf("PID: %d\n", pid);
	signal (SIGUSR1, &handler);
	signal (SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
