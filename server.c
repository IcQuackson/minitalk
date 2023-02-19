/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedgonca <pedgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:34:43 by pedgonca          #+#    #+#             */
/*   Updated: 2023/02/13 18:36:22 by pedgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <wchar.h>
#include <unistd.h>
#include <stdio.h>



/* void	signal_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR2)
	{
		//write(1, "1", 1);
		i |= (0x80 >> bit);
	}
	//else
		//write(1, "0", 1);
	bit++;
	if (bit == 8)
	{
		//write(1, " ", 1);
		//printf("----%d-----", i);
		//my_put_nbr(i);
		write(1, &i, i);
		//write(1, "\n", 1);
		bit = 0;
		i = 0;
	}
} */

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_put_nbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  if (n >= 10)
    {
      my_put_nbr(n / 10);
      my_putchar(n % 10 + '0');
    }
  if (n < 10)
    {
      my_putchar(n % 10 + '0');
    }
  return (n);
}

void    signal_handler(int signal, siginfo_t *info, void *context)
{
	static int			bit;
	static int			i;

	(void) context;
	if (signal == SIGUSR2)
	{
		//write(1, "1", 1);
		i |= (0x80 >> bit);
	}
	//else
		//write(1, "0", 1);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &i, i);
		bit = 0;
		i = 0;
	}
}

int main()
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("pid = %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
