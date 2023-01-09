/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:21:58 by emsoares          #+#    #+#             */
/*   Updated: 2023/01/06 10:33:26 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char_to_srv(int pid_srv, char char_msg)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((char_msg >> bit) & 1)
			kill(pid_srv, SIGUSR1);
		else
			kill (pid_srv, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid_srv;

	i = 0;
	if (argc != 3)
		ft_printf("Please, check the input --> ./client <PID> <Message>");
	if (argc == 3)
	{
		pid_srv = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_char_to_srv(pid_srv, argv[2][i]);
			i++;
		}
		send_char_to_srv(pid_srv, '\n');
		send_char_to_srv(pid_srv, '\0');
	}
	return (0);
}
