/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:20:43 by emsoares          #+#    #+#             */
/*   Updated: 2023/01/06 12:15:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	checkmsg(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	ft_printf("Message received Bro!");
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid_srv;
	struct sigaction	sa_client;

	i = 0;
	if (argc != 3)
		ft_printf("Please, check the input --> ./client <PID> <Message>");
	sa_client.sa_flags = SA_SIGINFO;
	sa_client.sa_sigaction = &checkmsg;
	sigemptyset(&sa_client.sa_mask);
	pid_srv = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		send_char_to_srv(pid_srv, argv[2][i]);
		i++;
	}
	send_char_to_srv(pid_srv, '\n');
	if (sigaction (SIGUSR1, &sa_client, NULL) == -1)
		ft_printf("ERROR IN SIGACTION!!!");
	send_char_to_srv(pid_srv, '\0');
	return (0);
}
