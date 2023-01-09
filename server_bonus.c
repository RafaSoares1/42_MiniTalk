/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:20:59 by emsoares          #+#    #+#             */
/*   Updated: 2023/01/06 13:45:35 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static char	c;

	(void) ucontext;
	if (signal == SIGUSR1)
		c = ((1 << bit) | c);
	if (signal == SIGUSR2)
		c = ((0 << bit) | c);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
			kill (info->si_pid, SIGUSR1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error! verify the input \n");
		return (0);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	if (sigaction (SIGUSR1, &sa, NULL) == -1)
		ft_printf("ERROR IN SIGACTION!!!");
	if (sigaction (SIGUSR2, &sa, NULL) == -1)
		ft_printf("ERROR IN SIGACTION!!!");
	while (1)
		pause();
	return (0);
}
