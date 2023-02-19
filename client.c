/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:32 by pedgonca          #+#    #+#             */
/*   Updated: 2023/02/19 14:26:51 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("The server got the message!\n");
}

void	send_str(int pid, char const *str)
{
	int					i;
	char				c;
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
			{
				kill(pid, SIGUSR2);
			}
			else
				kill(pid, SIGUSR1);
			usleep(700);
		}
	}
	while (++i < 8 && kill(pid, SIGUSR1) == 0)
		usleep(700);
}

int	main(int argc, char *argv[])
{
	int				server_pid;
	char const		*str;

	if (argc != 3)
		return (0);
	server_pid = ft_atoi(argv[1]);
	if (!server_pid)
	{
		ft_printf("Invalid pid\n");
		return (0);
	}
	str = argv[2];
	send_str(server_pid, str);
	return (0);
}
